#include <iostream>
#include <chrono>
#include <mpi.h>
// #include <iomanip>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int threads_size, thread_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &threads_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &thread_rank);

    // Синхронная часть
    int N = 6*threads_size;
    int common_arr[N], arr[6];
    if (thread_rank == 0) {
        for (int i = 0; i < N; i++)
            common_arr[i] = i + 1;
    }

    // std::cout.precision(6);
    // std::cout << std::fixed << std::setprecision(6);
    auto start = std::chrono::high_resolution_clock::now(); // std::clock_t start = std::clock();
    MPI_Scatter(&common_arr, 6, MPI_INT, &arr, 6, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = 0; i < 6; i++)
        arr[i] *= thread_rank;
    
    MPI_Gather(&arr, 6, MPI_INT, &common_arr, 6, MPI_INT, 0, MPI_COMM_WORLD);
    if (thread_rank == 0) {
        std::cout << "Synchronous data exchange took " 
                  << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count() // (double)(std::clock() - start) / CLOCKS_PER_SEC 
                  << " sec." << std::endl << std::endl;

        std::cout << "Resulting array of data (synchronous): ";
        for (int i = 0; i < N; i++)
            std::cout << common_arr[i] << " ";

        std::cout << std::endl << std::endl;

        // Инициализируем массив заново
        for (int i = 0; i < N; i++)
            common_arr[i] = i + 1;       
    }

    // Асинхронная часть
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Request req[2];
    MPI_Status status;
    int arr2[6];
    start = std::chrono::high_resolution_clock::now(); // std::clock();
    MPI_Iscatter(&common_arr, 6, MPI_INT, &arr2, 6, MPI_INT, 0, MPI_COMM_WORLD, &req[0]);
    MPI_Wait(&req[0], &status);
    for (int i = 0; i < 6; i++)
        arr2[i] *= thread_rank;
    
    MPI_Igather(&arr2, 6, MPI_INT, &common_arr, 6, MPI_INT, 0, MPI_COMM_WORLD, &req[1]);
    MPI_Wait(&req[1], &status);
    if (thread_rank == 0) {
        std::cout << "Asynchronous data exchange took " 
                  << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count() // static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC 
                  << " sec." << std::endl << std::endl;

        std::cout << "Resulting array of data (asynchronous): ";
        for (int i = 0; i < N; i++)
            std::cout << common_arr[i] << " ";

        std::cout << std::endl << std::endl;   
    }

    MPI_Finalize();
    return 0;
}
