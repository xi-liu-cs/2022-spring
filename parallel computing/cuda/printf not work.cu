#include <stdio.h>

__global__ void print()
{
    printf("thread %d\n", threadIdx.x);
}

int main()
{
    print<<<1, 1>>>();
    cudaDeviceSynchronize();
}