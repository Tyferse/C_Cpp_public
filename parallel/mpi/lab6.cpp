#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <mpi.h>


int* dot(int* a, int rows1, int cols1, int* b, int rows2, int cols2) {
    if (cols1 != rows2)
        return nullptr;
    
    int* r = new int[rows1 * cols2]();
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                r[i*rows1 + j]  += a[i*rows1 + k] * b[k*rows2 + j];
            }
        }
    }

    return r;
}


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int threads_size, thread_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &threads_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &thread_rank);

    int N = 2;
    int* a = new int[N * N]();
    int* b = new int[N * N]();
    int* product1;
    std::chrono::_V2::system_clock::time_point start;
    srand(time(NULL));

    if (thread_rank == 0) {
        for (int i = 0; i < N; i++) {
            std::cout << std::endl;
            for (int j = 0; j < N; j++) {
                a[i*N + j] = (int)(((float)rand() / RAND_MAX) * 4) + 1;
                b[i*N + j] = (int)(((float)rand() / RAND_MAX) * 4) + 1;
                std::cout << a[i*N + j] << " ";
            }
        }

        std::cout << std::endl;
        for (int i = 0; i < N; i++) {
            std::cout << std::endl;
            for (int j = 0; j < N; j++) {
                std::cout << b[i*N + j] << " ";
            }
        }
        std::cout << std::endl << std::endl;

        // Последовательное умножение
        start = std::chrono::high_resolution_clock::now();
        product1 = dot(a, N, N, b, N, N);

        std::cout << "Consecutive matrix multiplication has finished for "; 
        std::cout << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count();
        std::cout << " seconds." << std::endl << std::endl;

        for (int i = 0; i < N; i++) {
            std::cout << std::endl;
            for (int j = 0; j < N; j++) {
                std::cout << product1[i*N + j] << " ";
            }
        }

        std::cout << std::endl << std::endl;
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Bcast(a, N*N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);
    

    // Параллельное умножение
    MPI_Request req;
    MPI_Status status;
    if (thread_rank == 0)
        start = std::chrono::high_resolution_clock::now();

    int BLOCK_SIZE = N / threads_size, SUBBLOCK_SIZE = N % threads_size;
    int END_BLOCK = BLOCK_SIZE;
    if (SUBBLOCK_SIZE != 0) {
        BLOCK_SIZE = N / (threads_size - 1);
        SUBBLOCK_SIZE = N % (threads_size - 1);
        
        if (thread_rank == threads_size - 1) 
            END_BLOCK = SUBBLOCK_SIZE;
        else
            END_BLOCK = BLOCK_SIZE;
    }
    
    int* product2;
    if (BLOCK_SIZE == 0) {
        int ai = thread_rank;
        int* c = new int[N]();
        if (ai < N) {
            for (int x = 0; x < N; x += 1) {                
                for (int k = 0; k < N; k++) {
                    c[x] += a[ai*N + k] * b[k*N + x];
                }
            }
        }
        
        product2 = new int[N * threads_size]();
        MPI_Igather(c, N, MPI_INT, product2, N, MPI_INT, 0, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
    }
    else {
        int ai = thread_rank * BLOCK_SIZE;
        int* c = new int[BLOCK_SIZE * N]();
        for (int y = 0; y < END_BLOCK; y += 1) {
            for (int x = 0; x < N; x += 1) {                
                for (int k = 0; k < N; k++) {
                    c[y*N + x] += a[(y + ai)*N + k] * b[k*N + x];
                }
            }
        }

        product2 = new int[N * BLOCK_SIZE * threads_size]();
        MPI_Igather(c, N*BLOCK_SIZE, MPI_INT, product2, N*BLOCK_SIZE, MPI_INT, 0, MPI_COMM_WORLD, &req);
        MPI_Wait(&req, &status);
    }

    if (thread_rank == 0) {
        std::cout << "Parallel matrix multiplication has finished for "; 
        std::cout << (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start)).count();
        std::cout << " seconds." << std::endl << std::endl;

        int err = 0;
        // std::cout << BLOCK_SIZE << " " << SUBBLOCK_SIZE << std::endl;
        // if (BLOCK_SIZE == 0) {
        //     for (int i = SUBBLOCK_SIZE; i < N + SUBBLOCK_SIZE; i++) {
        //         std::cout << std::endl;
        //         for (int j = 0; j < N; j++) {
        //             std::cout << product2[i*N + j] << " ";
        //             if (abs(product1[i*N + j] - product2[i*N + j]) > 0.001) {
        //                 // std::cout << product1[i*N + j] << " != " << product2[i*N + j] 
        //                 //           << " at position " << i << " " << j << std::endl;
        //                 err += 1;
        //             }  
        //         }
        //     }
        // }
        // else {
            for (int i = 0; i < N; i++) {
                std::cout << std::endl;
                for (int j = 0; j < N; j++) {
                    std::cout << product2[i*N + j] << " ";
                    if (abs(product1[i*N + j] - product2[i*N + j]) > 0.001) {
                        // std::cout << product1[i*N + j] << " != " << product2[i*N + j] 
                        //           << " at position " << i << " " << j << std::endl;
                        err += 1;
                    }  
                }
            }
        // }

        std::cout << std::endl << std::endl;
        if (err == 0)
            std::cout << "Results of parallel and consecutive multiplication are equal" << std::endl;
        else
            std::cout << "Results of parallel and consecutive multiplication are not fully equal" << std::endl;
    }

    MPI_Finalize();
    return 0;
}
