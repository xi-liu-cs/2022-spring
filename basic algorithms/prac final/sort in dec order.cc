#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void print(int * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n\n");
}

bool cmp_dec(int i, int j)
{
    return i >= j;
}

int main()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(*a);
    sort(a, a + n, greater<int>());
    printf("1:\n");
    print(a, n);
    
    vector<int> vec(a, a + n);
    sort(vec.begin(), vec.end());
    printf("2:\n");
    print(vec.data(), n);
    
    sort(vec.begin(), vec.end(), cmp_dec);
    printf("3:\n");
    print(vec.data(), n);
}