#include <iostream>
#include <cuda_runtime.h>

#define N 16
#define M 12
#define BSIZE 256

using namespace std;


__global__ void VecMul(float A[N*M], float B[N*M], float C[N*M]) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    // printf("%d %d\n", idx, idy);
    if (idx < N*M) {
        // printf("%d %d\n", idx, idy);
        C[idx] = A[idx] * B[idx];
    }
}

__global__ void reduction(float in[N*M], float *out) {
    extern __shared__ float sdata[];

    // Индекс текущего потока
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Загружаем данные в shared memory
    sdata[tid] = (i < N*M) ? in[i] : 0; 
    __syncthreads();

    // Редукция
    for (int s = 1; s < blockDim.x; s *= 2) {
        if ((tid % (2*s)) == 0)
            sdata[tid] += sdata[tid + s];
        
        __syncthreads();
    }

    // Записываем результат в output
    if (tid == 0) {
        out[blockIdx.x] = sdata[0];
    }
}


int main() {
	float *A = new float[N*M];
    float *B = new float[N*M];
    // float *result = new float[N*M];

    // cout << "Maxrix A:\n";
  	for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i*M + j] = (float)(i * j);  
            B[i*M + j] = (float)(i * j) * 0.1;
            // cout << A[i*N + j] << " ";
        }
        // cout << endl;
    }

    // cout << "\nMatrix B:\n";
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << B[i*N + j] << " ";
    //     }
    //     cout << endl;
    // }
    
    float *dev_A, *dev_B, *dev_result;
	cudaMalloc((void**)&dev_A, sizeof(float) * N * M);
	cudaMalloc((void**)&dev_B, sizeof(float) * N * M);
    cudaMalloc((void**)&dev_result, sizeof(float) * N * M);

    cudaMemcpy(dev_A, A, sizeof(float) * N * M, cudaMemcpyHostToDevice);
	cudaMemcpy(dev_B, B, sizeof(float) * N * M, cudaMemcpyHostToDevice);
    // cudaMemcpy(dev_result, &result, sizeof(float) * N * M, cudaMemcpyHostToDevice);

    int blocks = (N*M + BSIZE - 1) / BSIZE;
    cout << "\nThreads: " << BSIZE << endl;
    cout << "Blocks: " << blocks << endl;

    float *reduced = new float[blocks], *dev_reduced;
    cudaMalloc((void**)&dev_reduced, sizeof(float) * blocks);

    cudaEvent_t start, end;
    cudaEventCreate(&start);
    cudaEventCreate(&end);

    cudaEventRecord(start, 0);

    VecMul<<<blocks, BSIZE>>>(dev_A, dev_B, dev_result);
	cudaDeviceSynchronize();

    reduction<<<blocks, BSIZE, BSIZE * sizeof(float)>>>(dev_result, dev_reduced);
    cudaDeviceSynchronize();

    cudaMemcpy(reduced, dev_reduced, sizeof(float) * blocks, cudaMemcpyDeviceToHost);

    float res_sum = 0.;
    for (int i = 0; i < blocks; i++) {
        cout << reduced[i] << endl;
        res_sum += reduced[i];
    }

    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);

    float elapsed;
    cudaEventElapsedTime(&elapsed, start, end);

    cout << endl << res_sum << " for " << elapsed << " miliseconds";
    

    delete[] A;
    delete[] B;
    delete[] reduced;
    delete &res_sum;
  
    cudaFree(dev_A);
	cudaFree(dev_B);
	cudaFree(&dev_result);
    cudaFree(&dev_reduced);

    cudaEventDestroy(start);
    cudaEventDestroy(end);

    return 0;
}
