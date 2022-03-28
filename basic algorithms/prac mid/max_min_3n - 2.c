#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
    int max;
    int min;
}s;

s * findmaxmin(int * a, int len)
{
    int winner[len / 2], loser[len / 2];
    int win_i = 0, los_i = 0;
    for(int i = 0; i < len; i += 2)
    {/* 2n / 2 = n comparisons to find winner 
    and loser within each pair */
        if(a[i] < a[i + 1])
        {
            loser[los_i++] = a[i];
            winner[win_i++] = a[i + 1]; 
        }
        else
        {
            loser[los_i++] = a[i + 1];
            winner[win_i++] = a[i]; 
        }
    }
    int max = (unsigned int)1 << 31, min = ((unsigned int)1 << 31) - 1;
    for(int i = 0; i < len / 2; ++i) /* (2n / 2) - 1 comparisons */
        if(winner[i] > max)
            max = winner[i];
    for(int i = 0; i < len / 2; ++i) /* (2n / 2) - 1 comparisons */
        if(loser[i] < min)
            min = loser[i];
    s * ret = malloc(sizeof(s));
    ret->max = max;
    ret->min = min;
    return ret;
} /* total = n + (n - 1) + (n - 1) = 3n - 2 comparisons */

int main()
{
    int a[] = {9, 3, 1, 4, 13, 14}; /* array of 2n elements */
    int len = sizeof(a) / sizeof(*a);
    s * ret = findmaxmin(a, len);
    printf("max = %d\nmin = %d\n", ret->max, ret->min);
}