#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    for(int i = a; i <= b - 1; i++)
    {
        if(ptr[i] <= piv)
        {
            swap(ptr, i, p_i);
            p_i++;
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

int * find_all_kth(int * A, int n, int k)
{
    int * ret = (int *)malloc(k * sizeof(int));
    for(int i = 1; i <= k; i++)
    {
        ret[i] = rand_select(A, 0, n - 1, i);
    }
    return ret;
}

int * find_L_to_kth(int * A, int n, int L, int k)
{
    int * ret = (int *)malloc((k - L + 1) * sizeof(int));
    for(int i = L; i <= k; i++)
    {
        ret[i - L + 1] = rand_select(A, 0, n - 1, i);
    }
    return ret;
}

int main()
{
    int a[] = {5, 2, 3, 7, 8, 0, 6};
    int len = sizeof(a) / sizeof(*a);
    printf("select = %d\n", rand_select(a, 0, len - 1, 5));

    int k = 5;
    int * ret = find_all_kth(a, len, k);
    printf("find_all_kth:\n");
    for(int i = 1; i <= k; i++)
    {
        printf("%d ", ret[i]);
    }
    free(ret);
    printf("\n");

    int l = 3;
    k = 5;
    ret = find_l_to_kth(a, len, l, k);
    printf("find_l_to_kth:\n");
    for(int i = 1; i <= k - l + 1; i++)
    {
        printf("%d ", ret[i]);
    }
    free(ret);
    printf("\n");
}