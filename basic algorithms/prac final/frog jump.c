#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define int_max ((unsigned)1 << 31) - 1

bool can_reach(int * a, int n)
{/* first, frog is on index n - 1, can jump a[i] at each index i towards front */
    int leftmost_i = n - 1;
    for(int i = n - 1; i >= 0; --i)
    {
        if(i < leftmost_i)
            return false;
        leftmost_i = fmin(leftmost_i, i - a[i]);
        if(leftmost_i <= 0)
            return true;
    }
    return false;
}

int min_jump(int * a, int n)
{/* first, frog is on index 0, can jump a[i] at each index i towards back */
    int jump[n];
    if(!n || !*a)
        return int_max;
    *jump = 0;
    for(int i = 1; i < n; ++i)
    {
        jump[i] = int_max;
        for(int j = 0; j < i; ++j)
        {
            if(i <= j + a[j] && jump[j] != int_max) /* index i can be reached from index j */
            {
                jump[i] = fmin(jump[i], jump[j] + 1);
                break;
            }
        }
    }
    return jump[n - 1];
}

int main()
{
    int a[] = {1, 0};
    int n = sizeof(a) / sizeof(*a);
    printf("a: can_reach = %d\n", can_reach(a, n));

    int a2[] = {1, 0, 2, 1, 3, 2};
    int n2 = sizeof(a2) / sizeof(*a2);
    printf("a2 = can_reach = %d\n", can_reach(a2, n2));
   
    int a3[] = {1, 0, 0, 0, 3};
    int n3 = sizeof(a3) / sizeof(*a3);
    printf("a3 = can_reach = %d\n", can_reach(a3, n3));
   
    int a4[] = {1, 0, 0, 0, 4};
    int n4 = sizeof(a4) / sizeof(*a4);
    printf("a4 = can_reach = %d\n", can_reach(a4, n4));
   
    printf("a: min_jump = %d\n", min_jump(a, n));
    printf("a2 = min_jump = %d\n", min_jump(a2, n2));
    printf("a3 = min_jump = %d\n", min_jump(a3, n3));
    printf("a4 = min_jump = %d\n", min_jump(a4, n4));   
}