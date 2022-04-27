#include <stdio.h>

__global__ void print()
{
    printf("print\n");
}

int main()
{
    print<<<1, 1>>>();
    cudaDeviceSynchronize();
}