#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <mpi.h>


char find_max(char* a, int n) {
    char m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > m)
            m = a[i];
    }

    return m;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int tsize, trank;
    MPI_Comm_size(MPI_COMM_WORLD, &tsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &trank);

    int N = 1000000000;
    char* arr = new char[N]();
    char global_max1, global_max2;
    std::chrono::_V2::system_clock::time_point start;
    srand(time(NULL));

    if (trank == 0) {
        for (int i = 0; i < N; i++)
            arr[i] = (char)(((float)rand() / RAND_MAX) * 127);
    
        // Последовательное нахождение максимума
        start = std::chrono::high_resolution_clock::now();
        global_max1 = find_max(arr, N);

        std::cout << "Consecutive maximum " << global_max1 << " has been found for "; 
        std::cout << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count();
        std::cout << " seconds." << std::endl << std::endl;
    }
    
    MPI_Barrier(MPI_COMM_WORLD);

    // Параллельное нахождение максимума
    MPI_Request req;
    MPI_Status status;
    // if (trank == 0)
    //     start = std::chrono::high_resolution_clock::now();

    int BLOCK_SIZE = N / tsize, SUBBLOCK_SIZE = N % tsize;
    int END_BLOCK = BLOCK_SIZE;
    if (SUBBLOCK_SIZE != 0) {
        BLOCK_SIZE = N / (tsize - 1);
        SUBBLOCK_SIZE = N % (tsize - 1);
        
        if (trank == tsize - 1) 
            END_BLOCK = SUBBLOCK_SIZE;
        else
            END_BLOCK = BLOCK_SIZE;
    }

    char* local_arr = new char[BLOCK_SIZE]();

    if (trank == 0) start = std::chrono::high_resolution_clock::now();
    MPI_Scatter(arr, BLOCK_SIZE, MPI_CHAR, local_arr, BLOCK_SIZE, MPI_CHAR, 0, MPI_COMM_WORLD);
    // MPI_Wait(&req, &status);

    char local_max = find_max(local_arr, END_BLOCK);
    // MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max2, 1, MPI_CHAR, MPI_MAX, 0, MPI_COMM_WORLD);
    // MPI_Wait(&req, &status);

    if (trank == 0) {
        std::cout << "Parallel maximum " << global_max2 << " has been found for "; 
        std::cout << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count();
        std::cout << " seconds." << std::endl << std::endl;
    }

    MPI_Finalize();
    return 0;
}
