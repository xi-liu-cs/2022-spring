#include <stdio.h>

int find_pairs(int * a, int n)
{/* A[1 . . . n] of n distinct integers, 
give an O(n^2) algorithm to find
number of pairs (x, y) such that x < y */
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i != j && a[i] < a[j])
                cnt++;
    return cnt;
}

int find_pairs2(int n)
{/* smallest element in the array appears in n − 1 such pairs,
second smallest element appears in n − 2 such pairs, etc
sum_{i = 1}^{n - 1} i = (n - 1)((n - 1) + 1) / 2 = n(n - 1) / 2 */
    return n * (n - 1) / 2;
}

int main()
{
    int a[] = {9, 4, 3, 13, 14};
    int n = sizeof(a) / sizeof(*a);
    printf("%d\n", find_pairs(a, n));
    printf("%d\n", find_pairs2(n));
}
