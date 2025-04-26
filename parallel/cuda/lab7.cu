#include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
#include <cuda_runtime.h>

using namespace std;

#define EPS 1e-4
#define N 8
#define BSIZE 4


__global__ void integrateBodies(float3 *newPos, float3 *newVel, float3 *oldPos, float3 *oldVel, float dt){
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int tid = threadIdx.x;
    float3 pos = oldPos[idx];
    float3 f = make_float3(0.0, 0.0, 0.0);
    __shared__ float3 sp[BSIZE];

    for(int i = 0; i < N; i += BSIZE) {
        sp[tid] = oldPos[i + tid];
        __syncthreads();

        float3 r;
        // for (int j = 0; j < BSIZE; j++) {
        r.x = sp[tid].x - pos.x;
        r.y = sp[tid].y - pos.y;
        r.z = sp[tid].z - pos.z;

        float invDist = 1.0 / sqrtf(r.x * r.x + r.y * r.y + r.z * r.z + EPS*EPS);
        float s = invDist * invDist * invDist;

        f.x += r.x * s;
        f.y += r.y * s;
        f.z += r.z * s;
        // }

        __syncthreads();
    }

    float3 vel = oldVel[idx];

    vel.x += f.x * dt;
    vel.y += f.y * dt;
    vel.z += f.z * dt;

    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
    pos.z += vel.x * dt;

    newPos[idx] = pos;
    newVel[idx] = vel;

    printf("%d %.4f %.4f %.4f\n", idx, newPos[idx].x, newPos[idx].y, newPos[idx].z);
}

void randomInit(float3 *a, int n) {
    for(int i = 0; i < n; ++i){
        a[i].x = 2 * (float)rand() / RAND_MAX - 1;
        a[i].y = 2 * (float)rand() / RAND_MAX - 1;
        a[i].z = 2 * (float)rand() / RAND_MAX - 1;
        cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
    }

    cout << endl;
}


int main(){
    float3 *p = new float3[N];
    float3 *v = new float3[N];

    float3 *p_dev[2] = {NULL, NULL};
    float3 *v_dev[2] = {NULL, NULL};

    randomInit(p, N);
    randomInit(v, N);

    cudaMalloc((void **) &p_dev[0], N * sizeof(float3));
    cudaMalloc((void **) &p_dev[1], N * sizeof(float3));
    cudaMalloc((void **) &v_dev[0], N * sizeof(float3));
    cudaMalloc((void **) &v_dev[1], N * sizeof(float3));

    cudaMemcpy(p_dev[0], p, N * sizeof(float3), cudaMemcpyHostToDevice);
    cudaMemcpy(v_dev[0], v, N * sizeof(float3), cudaMemcpyHostToDevice);

    cudaEvent_t start, end;
    cudaEventCreate(&start);
    cudaEventCreate(&end);

    cudaEventRecord(start, 0);

    int ind = 0;
    for(int i = 0; i < 90; i++, ind = (ind + 1) % 2) {
        cout << endl << i + 1 << " iteration" << endl;
        integrateBodies <<<N / BSIZE, BSIZE>>> (p_dev[(ind + 1) % 2], v_dev[(ind + 1) % 2], p_dev[ind], v_dev[ind], 1./30);
        cudaDeviceSynchronize();
    }    

    cudaMemcpy(p, p_dev[(ind + 1) % 2], N * sizeof(float3), cudaMemcpyDeviceToHost);
    cudaMemcpy(v, v_dev[(ind + 1) % 2], N * sizeof(float3), cudaMemcpyDeviceToHost);

    cudaEventRecord(end, 0);
    cudaEventSynchronize(end);

    float elapsed;
    cudaEventElapsedTime(&elapsed, start, end);

    cout << endl << "Evaluated for " << elapsed << " miliseconds" << endl;

    delete p, 
    delete v;

    cudaFree(p_dev[0]);
    cudaFree(p_dev[1]);
    cudaFree(v_dev[0]);
    cudaFree(v_dev[1]);

    return 0;
}
