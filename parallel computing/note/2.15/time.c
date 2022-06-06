// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void fun()
{
    printf("f() starts\n");
    printf("press enter to stop f");
    int len = 10;
    int * ret[len];
    for(int i = 0; i < len; i++)
    {
        ret[i] = malloc(sizeof(int));
        *ret[i] = 0;
    }
    while(1)
    {
        for(int i = 0; i < 100000000; i++)
            *ret[i % 10] += 1;
        if (getchar()) // cpu is not used when waiting for input
            break;
    }
    int sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += *ret[i];
        printf("*ret[%d] = %d\n", i, *ret[i]);
    }
    printf("sum = %d\n", sum);
}
  
// The main program calls fun() and measures cpu time taken by fun()
int main()
{
    clock_t start, end;
    start = clock();
    fun();
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // in seconds
  
    char str[20];
    sprintf(str, "cpu use %f seconds to execute f()\n", time_taken);
    printf(str);
    return 0;
}