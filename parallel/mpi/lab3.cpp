#include <iostream>
#include <mpi.h>
#include <random>
#include <time.h>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    srand(static_cast<unsigned int>(time(0)));

    int threads_size, thread_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &threads_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &thread_rank);
    
    int common_arr[4*threads_size], arr[4];
    if (thread_rank == 0) {
        std::cout << "Process 0 scatter data: ";
        for (int i = 0; i < 4*threads_size; i++) {
            common_arr[i] = (int)rand() % 120;
            std::cout << common_arr[i] << " ";
        }
        std::cout << std::endl << std::endl;
    }

    MPI_Scatter(&common_arr, 4, MPI_INT, &arr, 4, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 0; i < 4; i++)
        arr[i] *= thread_rank;
    
    // MPI_Barrier(MPI_COMM_WORLD);
    MPI_Gather(&arr, 4, MPI_INT, &common_arr, 4, MPI_INT, 0, MPI_COMM_WORLD);
    if (thread_rank == 0) {
        std::cout << "Process 0 gathered data: ";
        for (int i = 0; i < 4*threads_size; i++) 
            std::cout << common_arr[i] << " ";

        std::cout << std::endl << std::endl;
    }

    int local_sum, global_sum;
    for (int i = 0; i < 4; i++)
        local_sum += arr[i];

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Allreduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    std::cout << "Process " << thread_rank << " got total sum of all multiplied elements: " << global_sum << std::endl << std::endl;

    MPI_Finalize();
    return 0;
}
