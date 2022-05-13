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
    int buf[] = {0, 0, 8, 8};
    int B[4];
    if(!my_rank)
        memcpy(B, buf, 4 * sizeof(int));
    MPI_Bcast(B, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Finalize();
    printf("my_rank = %d\n", my_rank);
    print(B, 4);
}