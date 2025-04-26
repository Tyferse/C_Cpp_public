#include <iostream>
#include <random>
// #include <time.h>
#include <chrono>
#include <iomanip>
#include <mpi.h>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int threads_size, thread_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &threads_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &thread_rank);

    MPI_Request req;
    MPI_Status status;

    int N = 1000000000; 
    int iters = N / threads_size;
    // int common_arr[threads_size];
    // int arr[iters];
    int local_res = 0, result;

    // srand(static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count()));
    srand(time(NULL));
    std::chrono::_V2::system_clock::time_point start;
    if (thread_rank == 0)
        start = std::chrono::high_resolution_clock::now();

    // MPI_Iscatter(&common_arr, 6, MPI_INT, &arr, 6, MPI_INT, 0, MPI_COMM_WORLD, &req[0]);
    // MPI_Wait(&req[0], &status);

    for (int i = 0; i < iters; i++) {
        float x = ((float)rand() / RAND_MAX) * 2 - 1, y = ((float)rand() / RAND_MAX) * 2 - 1;
        if (x*x + y*y <= 1) 
            local_res += 1;
    }
    
    MPI_Ireduce(&local_res, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD, &req);
    MPI_Wait(&req, &status);

    if (thread_rank == 0) {
        std::cout << "Approximation of Pi: " << 4 * (long double)result / (iters * threads_size) << std::setprecision(12) << std::endl << std::endl;
        std::cout << "Time taken: " 
                //   << static_cast<double>(clock() - start) / CLOCKS_PER_SEC
                  << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count()
                  << " seconds." << std::endl << std::endl; 
    }

    MPI_Finalize();
    return 0;
}
