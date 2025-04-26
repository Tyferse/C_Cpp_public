#include <iostream>
#include <cuda_runtime.h>

#define N 16
#define M 12
#define BSIZE 16

using namespace std;


__global__ void MatScalar(float A[N][M], float B[N][M], float *result) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    int idy = threadIdx.y + blockIdx.y * blockDim.y;
    // printf("%d %d\n", idx, idy);
    if (idx < N && idy < M) {
        // printf("%d %d\n", idx, idy);
        atomicAdd(result, A[idx][idy] * B[idx][idy]);
    }
}


int main() {
		float (*A)[M] = new float[N][M];
    float (*B)[M] = new float[N][M];
  	float result = 0.0f;

    // cout << "Maxrix A:\n";
  	for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = (float)(i * j); 
            B[i][j] = (float)(i * j) / 10.;
            // cout << A[i][j] << " ";
        }
        // cout << endl;
    }

    // cout << "\nMatrix B:\n";
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << B[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    float (*dev_A)[M], (*dev_B)[M], *dev_result;
	  cudaMalloc((void**)&dev_A, sizeof(float) * N * M);
	  cudaMalloc((void**)&dev_B, sizeof(float) * N * M);
    cudaMalloc((void**)&dev_result, sizeof(float));
 
    cudaMemcpy(dev_A, A, sizeof(float) * N * M, cudaMemcpyHostToDevice);
	  cudaMemcpy(dev_B, B, sizeof(float) * N * M, cudaMemcpyHostToDevice);
    cudaMemcpy(dev_result, &result, sizeof(float), cudaMemcpyHostToDevice);


    dim3 threadsPerBlock(N >= BSIZE ? BSIZE: N, M >= BSIZE ? BSIZE : N);
    dim3 numBlocks((N + threadsPerBlock.x - 1) / threadsPerBlock.x, (M + threadsPerBlock.y - 1) / threadsPerBlock.y);
    cout << "\nThreads: " << threadsPerBlock.x << " " << threadsPerBlock.y << endl;
    cout << "Blocks: " << numBlocks.x << " " << numBlocks.y << endl;

    cudaEvent_t start, end;
    cudaEventCreate(&start);
    cudaEventCreate(&end);

    cudaEventRecord(start, 0);

    MatScalar<<<numBlocks, threadsPerBlock>>>(dev_A, dev_B, dev_result);
		// cudaDeviceSynchronize();

	  cudaMemcpy(&result, dev_result, sizeof(float), cudaMemcpyDeviceToHost);

    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);

    float elapsed;
    cudaEventElapsedTime(&elapsed, start, end);

    cout << endl << result << " for " << elapsed << " miliseconds";
  
    delete[] A;
    delete[] B;
    delete &result;
  
    cudaFree(dev_A);
	  cudaFree(dev_B);
	  cudaFree(&dev_result);

    cudaEventDestroy(start);
    cudaEventDestroy(end);

    return 0;
}
