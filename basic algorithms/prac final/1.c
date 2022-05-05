#include <stdio.h>
#include <stdlib.h>

void print(int * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int cmp_dec(const void * p1, const void * p2)
{
    return *(int *)p2 - *(int *)p1;
}

int max_ball(int * diameter, int dia_sz, int * length, int len_sz)
{
    qsort(diameter, dia_sz, sizeof(int), cmp_dec); print(diameter, dia_sz);
    qsort(length, len_sz, sizeof(int), cmp_dec); print(length, len_sz);
    int i = 0, j = 0, count = 0;
    while(i < dia_sz)
    {
        if(diameter[i] <= length[j])
        {
            ++count; ++i; ++j;
        }
        else
            ++i;
    }
    return count;
}

int main()
{
    int diameter[] = {4, 5, 5, 9, 1, 10, 2, 7},
    dia_sz = sizeof(diameter) / sizeof(*diameter),
    length[] = {9, 9, 10, 5, 3, 1, 1, 1, 2},
    len_sz = sizeof(length) / sizeof(*length);
    printf("max_ball = %d\n", max_ball(diameter, dia_sz, length, len_sz));
}