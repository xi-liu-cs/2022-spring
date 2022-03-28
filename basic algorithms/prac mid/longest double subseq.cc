#include <stdio.h>
#include <iostream>
using namespace std;

int longest_double_subseq(int * a, int n)
{/* longest subseq s.t. 2 * subseq[i] <= subseq[i + 1] */
    int memo[n];
    for(int i = 0; i < n; ++i)
    {
        memo[i] = 1;
        for(int j = 0; j < i; ++j)
            if(2 * a[j] <= a[i])
                memo[i] = max(memo[i], memo[j] + 1);
            
    }
    return memo[n - 1];
}

int main()
{
    int a[] = {1, 9, 4, 3, 13, 26};
    int n = sizeof(a) / sizeof(*a);
    cout << longest_double_subseq(a, n);
}