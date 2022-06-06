// https://www.geeksforgeeks.org/implement-your-own-sizeof/
#include <stdio.h>

#define my_sizeof(type) (char *)(&type + 1) - (char *)(&type)

int main()
{
    int x[8];
    printf("%ld\n", my_sizeof(x));
}