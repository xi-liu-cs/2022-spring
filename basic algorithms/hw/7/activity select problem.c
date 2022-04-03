#include <stdio.h>
#include <stdlib.h>

typedef struct activity
{
    int start,
    finish;
}activity;

activity a[] =
{
    {0, 6},
    {1, 2},
    {3, 4},
    {5, 9},
    {5, 7},
    {8, 9},
};

int n = sizeof(a) / sizeof(*a);

void print_activity(activity * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("start = %d, finish = %d\n", a[i].start, a[i].finish);
}

activity * recur_activity_sel(int * start, int * finish, int i, int n, activity * ret, int * ret_sz)
{
    if(!i)
        ret = malloc(n * sizeof(activity));
    int a_i = i + 1;
    while(a_i < n)
    {
        if(finish[i] <= start[a_i])
            break;
        ++a_i;
    }
    if(a_i < n)
    {
        ret[(*ret_sz)++] = a[a_i];
        return recur_activity_sel(start, finish, a_i, n, ret, ret_sz);
    }
    return ret;
}

activity * activity_sel(int * start, int * finish, int n, int * ret_sz)
{
    activity * ret = malloc(n * sizeof(activity));
    *ret = *a;
    int f_i = 0;
    for(int a_i = 1; a_i < n; ++a_i)
    {
        if(finish[f_i] <= start[a_i])
        {
            ret[(*ret_sz)++] = a[a_i];
            f_i = a_i;  
        }
    }
    return ret;
}

int cmp_finish(const void * p1, const void * p2)
{
    activity * a1 = (activity *)p1, * a2 = (activity *)p2;
    return a1->finish - a2->finish;
}

int cmp(const void * p1, const void * p2)
{
    int * a1 = (int *)p1, * a2 = (int *)p2;
    return *a1 - *a2;
}

int color_interval(int * s, int * f, int n)
{
    qsort(s, n, sizeof(int), cmp);
    qsort(f, n, sizeof(int), cmp);
    int i = 0, j = 0, 
    max_overlap = 0, overlap = 0, max_overlap_time = 0;
    for(int i = 0, j = 0; i < n && j < n; )
    {
        if(s[i] < f[j])
        {
            ++overlap;
            if(max_overlap < overlap)
            {
                max_overlap = overlap;
                max_overlap_time = s[i];
            }
            ++i;
        }
        else
        {
            --overlap;
            ++j;
        }
    }
    printf("\nmax_overlap_time = %d\n", max_overlap_time);
    return max_overlap;
}

int main()
{/* start[]  =  {1, 3, 0, 5, 8, 5};
    finish[] =  {2, 4, 6, 7, 9, 9}; */
   
    print_activity(a, n);
    qsort(a, n, sizeof(activity), cmp_finish);
    printf("\nafter sort by finish time:\n");
    print_activity(a, n);
   
    int start[n], finish[n];
    for(int i = 0; i < n; ++i)
    {
        start[i] = a[i].start;
        finish[i] = a[i].finish;
    }
   
    printf("\nrecur_activity_sel:\n");
    int ret_sz = 0;
    activity * ret = recur_activity_sel(start, finish, 0, n, 0, &ret_sz);
    print_activity(ret, ret_sz);
   
    printf("\nactivity_sel:\n");
    int ret_sz2 = 0;
    activity * ret2 = activity_sel(start, finish, n, &ret_sz2);
    print_activity(ret2, ret_sz2);
    
    printf("\ncolor_interval: %d\n", color_interval(start, finish, n));
}