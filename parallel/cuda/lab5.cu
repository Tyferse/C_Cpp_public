#include <iostream>
#include <cuda_runtime.h>

using namespace std;

#define N 16
#define BSIZE 16


__global__ void transpose(float *in, float *out) {
    int j = blockIdx.x * blockDim.x + threadIdx.x;
    int i = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < N && j < N) {
        out[i + N*j] = in[j + N*i];
    }
}

int main() {
    float (*A)[N] = new float[N][N];
    float (*B)[N] = new float[N][N];

    cout << "Initial matrix A:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = (float)(i*N + j + 1);
            cout << A[i][j] << ' ';  
        }
        cout << endl;
    }

    float *dev_A, *dev_B;
    cudaMalloc((void**)&dev_A, N*N * sizeof(float));
    cudaMalloc((void**)&dev_B, N*N * sizeof(float));

    cudaMemcpy(dev_A, A, N*N * sizeof(float), cudaMemcpyHostToDevice);

    cudaEvent_t start, end;
    cudaEventCreate(&start);
    cudaEventCreate(&end);

    dim3 threads(N >= BSIZE ? BSIZE: N, N >= BSIZE ? BSIZE : N);
    dim3 blocks((N + threads.x - 1) / threads.x, (N + threads.y - 1) / threads.y);
    cout << "\nThreads: " << threads.x << " " << threads.y << endl;
    cout << "Blocks: " << blocks.x << " " << blocks.y << endl;

    cudaEventRecord(start, 0);

    transpose<<<blocks, threads>>>(dev_A, dev_B);

    cudaMemcpy(B, dev_B, N*N * sizeof(float), cudaMemcpyDeviceToHost);

    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);

    cout << "Transposed matrix:" << endl;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

    float elapsed;
    cudaEventElapsedTime(&elapsed, start, end);

    cout << endl << "for " << elapsed << " miliseconds" << endl;

    delete[] A;
    delete[] B;

    cudaFree(dev_A);
    cudaFree(dev_B);

    cudaEventDestroy(start);
    cudaEventDestroy(end);

    return 0;
}
