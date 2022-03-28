#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void swap(int * ptr, int i, int j)
{
    int t = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = t;
}

int partition(int * ptr, int a, int b)
{
    int p_i = a; //partition index
    int piv = ptr[b];
    for(int i = a; i <= b - 1; ++i)
    {
        if(ptr[i] <= piv)
        {
            swap(ptr, i, p_i);
            ++p_i;
        }
    }
    swap(ptr, p_i, b);
    return p_i; 
}

int rand_partition(int * ptr, int a, int b)
{
    int rand_i = 0;
    srand(time(0));
    if(b - a != 0) 
        rand_i = a + rand() % (b - a);
    swap(ptr, rand_i, b);
    return partition(ptr, a, b);
}

int rand_select(int * A, int left, int right, int i)
{
    if(left == right)
        return A[left];
    int rand_i = rand_partition(A, left, right);
    int k = rand_i - left + 1;
    if(i == k)
        return A[rand_i];
    else if(i < k)
        return rand_select(A, left, rand_i - 1, i);
    else
        return rand_select(A, rand_i + 1, right, i - k);
}

int main()
{
    int a[] = {1, 9, 4, 3, 13, 14};
    int n = sizeof(a) / sizeof(*a);
    cout << rand_select(a, 0, n, 2);
}