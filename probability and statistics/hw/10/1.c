#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int vals[] = {3, 7, 8, 5, 12, 14, 21, 15, 35, 18, 14};
	int n = sizeof(vals) / sizeof(*vals);
	qsort(vals, n, sizeof(int), cmp);
	printf("n = %d\n", n);
	for(int i = 0; i < n; ++i)
		printf("%d, ", vals[i]);
}