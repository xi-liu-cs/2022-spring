#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool can_reach(int * a, int n)
{
    int leftmost_i = n - 1;
    for(int i = n - 1; i >= 0; --i)
    {
        if(leftmost_i <= i)
        {
            leftmost_i = fmin(leftmost_i, i - a[i]);
            if(leftmost_i <= 0)
                return true;
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 0, 2, 2, 1, 1};
    int n = sizeof(a) / sizeof(*a);
    printf("a: can_reach = %d\n", can_reach(a, n));

    int a2[] = {1, 0, 2, 1, 3, 2};
    int n2 = sizeof(a2) / sizeof(*a2);
    printf("a2 = can_reach = %d\n", can_reach(a2, n2));
    
    int a3[] = {1, 0, 1, 3, 3};
    int n3 = sizeof(a3) / sizeof(*a3);
    printf("a3 = can_reach = %d\n", can_reach(a3, n3));
    
    int a4[] = {1, 1, 0, 0, 2, 4};
    int n4 = sizeof(a4) / sizeof(*a4);
    printf("a4 = can_reach = %d\n", can_reach(a4, n4));
    
    int a5[] = {1, 1, 0, 0, 0, 0, 0, 0, 0};
    int n5 = sizeof(a5) / sizeof(*a5);
    printf("a5 = can_reach = %d\n", can_reach(a5, n5));
}