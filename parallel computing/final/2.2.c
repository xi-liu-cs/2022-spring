#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

void print(int * a, int n)
{
    for(int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char ** argv)
{
    int comm_sz, /* num processes */
    my_rank;
    MPI_Init(&argc , &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int A[4], B[4];
    if(!my_rank)
    {
        int buf[] = {1, 8, 9, 8};
        memcpy(A, buf, 4 * sizeof(int));
    }
    if(my_rank == 1)
    {
        int buf[] = {2, 7, 10, 15};
        memcpy(A, buf, 4 * sizeof(int));
    }
    if(my_rank == 2)
    {
        int buf[] = {3, 6, 11, 14};
        memcpy(A, buf, 4 * sizeof(int));
    }
    if(my_rank == 3)
    {
        int buf[] = {4, 5, 12, 13};
        memcpy(A, buf, 4 * sizeof(int));
    }
    MPI_Allreduce(A, B, 4, MPI_INT, MPI_BAND, MPI_COMM_WORLD);
    MPI_Finalize();
    printf("my_rank = %d\n", my_rank);
    print(B, 4);
}