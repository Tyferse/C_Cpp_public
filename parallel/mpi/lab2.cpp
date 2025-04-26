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

    int sumn = 0, rsumn, maxn = -100, rmaxn, nums[10];
    if (thread_rank == 0) {
        for (int i = 0; i < 10; i++) {        
            nums[i] = rand() % 100;
        }

        std::cout << "Process 0 broadcasting data..." << std::endl << std::endl;
    }
    
    MPI_Bcast(nums, 10, MPI_INTEGER, 0, MPI_COMM_WORLD);
    if (thread_rank > 0) {
        for (int i = 0; i < 10; i++) { 
            nums[i] *= thread_rank;
            
            sumn += nums[i];
            if (nums[i] > maxn)                
                maxn = nums[i];
        }
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&sumn, &rsumn, 1, MPI_INTEGER, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&maxn, &rmaxn, 1, MPI_INTEGER, MPI_MAX, 0, MPI_COMM_WORLD);

    // std::cout << rsumn << std::endl;
    if (thread_rank == 0) {
        std::cout << "Total sum of all elements: " << rsumn << std::endl << std::endl;
        std::cout << "Maximum element: " << rmaxn << std::endl << std::endl;
    }

    MPI_Finalize();
    return 0;
}
