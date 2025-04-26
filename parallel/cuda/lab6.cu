#include <iostream>
#include <cuda_runtime.h>

using namespace std;

#define N 4
#define BSIZE 2


__global__ void matMul(float *a, float *b, float *c) {
    int bx = blockIdx.x;
    int by = blockIdx.y;
    int tx = threadIdx.x;
    int ty = threadIdx.y;

    // Индекс начала первой подматрицы А, обрабатываемой блоком.
    int aBegin = N * BSIZE * by;
    int aEnd = aBegin + N - 1;
     
    // Шаг перебора подматриц А. 
    int aStep = BSIZE; 
    
    // Индекс первой подматрицы B обрабатываемой блоком. 
    int bBegin = BSIZE * bx;

    // Шаг перебора подматриц В, 
    int bStep = BSIZE * N; 
    float sum = 0.0; // Вычuсляемый элеменm С. 
  
    // Цuкл по 16*16 подматpицaм 
    for (int ia = aBegin, ib = bBegin; ia < aEnd; ia += aStep, ib += bStep)  { 
        // Очередная подматрица А в разделяемой памяти. 
        __shared__ float as[BSIZE][BSIZE]; 
        // Очередная подматрица В в разделяемой памяти. 
        __shared__ float bs[BSIZE][BSIZE];

        // Загрузuть по одному элементу из А и В в разделяемую nамять. 
        as[ty][tx] = a[ia + N*ty + tx];
        bs[ty][tx] = b[ib + N*ty + tx];
 
        // Дождаться, когда обе подматрицы будут nолностью загружены. 
        __syncthreads(); 

        // Вычuсляем нужный элеменm nроuзведенuя зааруженных подматриц.
        int ic = N*BSIZE * by + BSIZE * bx; 
        for (int k = 0; k < BSIZE; k++) {
            sum += as[ty][k] * bs[k][tx];

            // дождаться, пока все осmальные нumu блока закончаm вычuслять свои элеменmы. 
            __syncthreads();

            // Заnuсать результат.  
            c[ic + N*ty + tx] = sum; 
        }
    }
}

int main() {
    float *A = new float[N*N];
    float *B = new float[N*N];
    float *C = new float[N*N];

    cout << "Initial matrix A (B = 0.1 * A):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) { 
            A[i*N + j] = (float)(i + j);
            B[i*N + j] = (i + j) * 0.1;
            cout << A[i*N + j] << " ";
        }

        cout << endl;
    }

    float *dev_A, *dev_B, *dev_C;
    cudaMalloc((void**)&dev_A, N*N * sizeof(float));
    cudaMalloc((void**)&dev_B, N*N * sizeof(float));
    cudaMalloc((void**)&dev_C, N*N * sizeof(float));

    cudaMemcpy(dev_A, A, N*N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_B, B, N*N * sizeof(float), cudaMemcpyHostToDevice);

    cudaEvent_t start, end;
    cudaEventCreate(&start);
    cudaEventCreate(&end);

    dim3 threads(N >= BSIZE ? BSIZE: N, N >= BSIZE ? BSIZE : N);
    dim3 blocks((N + threads.x - 1) / threads.x, (N + threads.y - 1) / threads.y);
    cout << "\nThreads: " << threads.x << " " << threads.y << endl;
    cout << "Blocks: " << blocks.x << " " << blocks.y << endl;

    cudaEventRecord(start, 0);

    matMul<<<blocks, threads>>>(dev_A, dev_B, dev_C);

    cudaMemcpy(C, dev_C, N*N * sizeof(float), cudaMemcpyDeviceToHost);

    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);

    cout << "Matrix multiplication result:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i*N + j] << ' ';
        }
        cout << endl;
    }

    float elapsed;
    cudaEventElapsedTime(&elapsed, start, end);

    cout << endl << "for " << elapsed << " miliseconds" << endl;

    delete[] A;
    delete[] B;
    delete[] C; 

    cudaFree(dev_A);
    cudaFree(dev_B);
    cudaFree(dev_C);

    cudaEventDestroy(start);
    cudaEventDestroy(end);

    return 0;
}
