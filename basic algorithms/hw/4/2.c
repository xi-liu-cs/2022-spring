#include <stdio.h>

int rand_select(int * A, int left, int right, int i);

void swap(int * ptr, int i, int j)
{
    int t = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = t;
}

int partition(int * ptr, int a, int b, int m)
{
    int p_i = a; //partition index
    int piv = m;
    for(int i = a; i <= b; i++)
    {
        if(ptr[i] <= piv)
        {
            swap(ptr, i, p_i);
            p_i++;
        }
    }
    return p_i; 
}

int rand_partition(int * ptr, int left, int right)
{
    int n = right - left + 1;
    int median_th = n / 2;
    int med = rand_select(ptr, left, left + n, median_th);
    return partition(ptr, left, right, med);
}

int rand_select(int * A, int left, int right, int i)
{
    if(left == right)
        return A[left];
    int n = right - left + 1;
    int piv_i = rand_partition(A, left, left + n / 5);
    int k = piv_i - left + 1;
    if(i == k)
        return A[piv_i];
    else if(i < k)
        return rand_select(A, left, piv_i - 1, i);
    else
        return rand_select(A, piv_i + 1, right, i - k);
}

int main()
{
    int a[] = {8, 5, 10, 3, 9, 12, -1, 3, 7, 6};
    int len = sizeof(a) / sizeof(*a);
    for(int i = len; i >= 1; i--)
        printf("sel(%d) = %d\n", i, rand_select(a, 0, len - 1, i));
}