#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__global__ void add(int a, int b, int * dsum)
{
    *dsum = a + b;
}

int main()
{
    int a = 3, b = 2;
    int * hsum = (int *)malloc(sizeof(int)), * dsum;
    cudaMalloc(&dsum, sizeof(int));
    add<<<1, 1>>>(a, b, dsum);
    cudaMemcpy(hsum, dsum, sizeof(int), cudaMemcpyDeviceToHost);
    printf("hsum = %d\n", *hsum);
    free(hsum);
    cudaFree(dsum);
}
