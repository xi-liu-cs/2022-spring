#include <stdio.h>

__global__ void print(char ** dest)
{
    const char * temp = "123";
    int i;
    for(i = 0; i < 3; ++i)
        (*dest)[i] = temp[i];
    (*dest)[i] = '\0';
}

int main()
{
    char * str = (char *)malloc(4);
    print<<<1, 1>>>(&str);
    printf(str);
    cudaDeviceSynchronize();
}
