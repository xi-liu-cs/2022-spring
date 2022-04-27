#include <stdio.h>
#include <cuda.h>

__global__ void vec_add(float * x, float * y, float * z, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i < n)
        z[i] = x[i] + y[i];
}

void alloc_vec(float ** xp, float ** yp, float ** zp, int n)
{
    cudaMallocManaged(xp, n * sizeof(float));
    cudaMallocManaged(yp, n * sizeof(float));
    cudaMallocManaged(zp, n * sizeof(float));
}

__global__ void init_vec(float * x, float * y)
{
    float a1[] = {1.0, 2.0, 3.0},
    a2[] = {1.0, 2.0, 3.0};
    int n = sizeof(a1) / sizeof(*a1);
    for(int i = 0; i < n; ++i)
    {
        x[i] = a1[i];
        y[i] = a2[i];
    }   
}

void print(float * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%f ", a[i]);
    printf("\n");
}

int main()
{
    int blk_ct = 1 /* block_count */,
    th_per_blk = 1 /* thread_per_block */;
    int n = 3;
    float * x, * y, * z;
    alloc_vec(&x, &y, &z, n);
    init_vec<<<blk_ct, th_per_blk>>>(x, y);
    vec_add<<<blk_ct, th_per_blk>>>(x, y, z, n);
    print(z, n);   
    cudaDeviceSynchronize();
}