#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool canreach(int * a, int n)
{
    bool memo[n];
    *memo = true;
    for(int i = 1; i < n; i++)
    {
        if(!a[i])
        {
            memo[i] = false;
            continue;
        }
        else if(i - a[i] <= 0)
        {
            memo[i] = true;
            continue;
        }
        else
        {
            for(int j = 1; j <= a[i] && i - j >= 1; j++)
            {
                if(memo[i - j])
                {
                    memo[i] = memo[i - j];
                    continue;
                }
            }
        }
    }
    return memo[n - 1];
}

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

bool front_to_back_can_reach(int * a, int n)
{
    int rightmost = 0;
    for(int i = 0; i < n; ++i) 
    {
        if(i <= rightmost) 
        {
            rightmost = fmax(rightmost, i + a[i]);
            if(rightmost >= n - 1) 
                return true;
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 0, 2, 0, 0, 3, 0, 2};
    int n = sizeof(a) / sizeof(*a);
    printf("canreach = %d\n", canreach(a, n));
    printf("can_reach = %d\n", can_reach(a, n));
    
    int a2[] = {2, 0, 3, 0, 0, 2, 0, 1};
    int n2 = sizeof(a2) / sizeof(*a2);
    printf("\nfront_to_back_can_reach = %d\n", front_to_back_can_reach(a2, n2));
}