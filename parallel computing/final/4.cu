#include <stdio.h>
#include <cuda.h>

__global__ void printing()
{
    __shared__ int x;
    x = 7;
    if(blockIdx.x > 0)
        printf("blk.x = %d\n", blockIdx.x);
    else
        printf("x = %d\n", x);
    __syncthreads();
    printf("thread.x = %d\n", threadIdx.x);
}

int main()
{
    printing<<<3, 2>>>(); /* <<<blk_per_grid, th_per_blk>>> */
    cudaDeviceSynchronize();
}