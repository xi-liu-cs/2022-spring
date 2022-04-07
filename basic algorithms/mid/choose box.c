#include <stdio.h>
#include <math.h>

int choose_box_rec(int * a, int n, int k)
{
    if(n - 1 < 0)
        return 0;
    return fmax(choose_box_rec(a, n - 1, k), 
    a[n - 1] + choose_box_rec(a, n - k - 1, k));
}

int choose_box(int * a, int n, int k)
{
    int memo[n];
    for(int i = 0; i < n; ++i)
    {
        int a1 = 0, a2 = 0;
        if(i - 1 >= 0)
            a1 = memo[i - 1];
        if(i - k - 1 >= 0)
            a2 = memo[i - k - 1];
        memo[i] = fmax(a1, a2 + a[i]);   
    }
    return memo[n - 1];
}


int choose(int * c, int n, int k)
{
    int memo[n];
    for(int i = 0; i < n; ++i)
    {
    	memo[i] = c[i];
        for(int j = 0; j < i; ++j)
        {
    	    if(i - j > k) /* boxes must be more than k distance apart */
    		    memo[i] = fmax(memo[i], c[i] + memo[j]);
        }
    }
    return memo[n - 1];
}

int main()
{
    int a[] = {-7, -3, 6, 8, 11, 12};
    int n = sizeof(a) / sizeof(*a);
    int k = 2;
    printf("choose_box_rec = %d\n", choose_box_rec(a, n, k));
    printf("choose_box = %d\n", choose_box(a, n, k));
    printf("choose_box = %d\n", choose(a, n, k));
}