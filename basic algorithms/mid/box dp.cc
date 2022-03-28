#include <iostream>
using namespace std;

int dp(int * c, int n, int k)
{
    int memo[n];
    for(int i = 0; i < n; ++i)
    {
        memo[i] = c[i];
    	for(int j = 0; j < i; ++j)
        {
    	    if(i - j >= k) /* boxes must be more than k distance apart */
    		    memo[i] = max(memo[i], c[j] + memo[i - j]);
        }
    }
    return memo[n - 1];
}

int main()
{
    int a[] = {1, 3, 5, 7, 2, 4, 6, 8, 0};
    int n = sizeof(a) / sizeof(*a);
    cout << dp(a, n, 3) << "\n";
}