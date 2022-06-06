/* algorithm book 241
https://stackoverflow.com/questions/33021258/median-of-medians-not-working-properly */
#include <stdio.h>

void swap(int * ptr, int i, int j)
{
    int t = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = t;
}

void insert_sort(int * ptr, int len)
{
    for(int i = 1; i < len; i++)
    {
        int key = ptr[i];
        int j = i - 1;
        while(j >= 0 && ptr[j] > key)
        {
            ptr[j + 1] = ptr[j];
            j--;
        }
        ptr[j + 1] = key;
    }
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

int find_median(int * ptr, int left, int right)
{
    int n = right - left + 1;
    insert_sort(ptr + left, n);
    return ptr[left + n / 2];
}


int med_of_medians(int * A, int left, int right, int i)
{
    if(left == right)
        return A[left];
    int n = right - left + 1;
    int med[(n + 4) / 5];
    int m_i;
    for(m_i = 0; m_i < n / 5; m_i++)
        med[m_i] = find_median(A, left + (m_i * 5), left + (m_i * 5) + 4);
    if(n % 5 > 0)
    {
        if(n / 5 >= 1)
            med[m_i] = find_median(A, left + (n / 5 - 1) * 5, right);
        m_i++;
    }
    int median;
    if(m_i == 1)
        median = med[0];
    else
        median = find_median(med, 0, m_i - 1);
    int piv_i = partition(A, left, right, median);
    int rank = piv_i - left + 1;   
    if(i == rank)
        return A[piv_i];
    else if(i < rank)
        return med_of_medians(A, left, piv_i - 1, i);
    else
        return med_of_medians(A, piv_i + 1, right, i - rank);
}

int main()
{
    int a[] = {8, 5, 10, 3, 9, -1, 3, 7, 6};
    int len = sizeof(a) / sizeof(*a);
    for(int i = 1; i <= len; i++)
        printf("med_of_medians(%d) = %d\n", i, med_of_medians(a, 0, len - 1, i));
}