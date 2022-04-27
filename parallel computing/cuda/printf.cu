#include <stdio.h>

__global__ void print(char ** dstr)
{
    const char * temp = "123";
    int i;
    for(i = 0; i < 3; ++i)
        (*dstr)[i] = temp[i];
    (*dstr)[i] = '\0';
}

int main()
{
    char * hstr = (char *)malloc(4), * dstr;
    cudaMalloc(&dstr, 4);
    print<<<1, 1>>>(&dstr);
    cudaMemcpy(hstr, dstr, 4, cudaMemcpyDeviceToHost);
    printf(hstr);
    cudaDeviceSynchronize();
}
