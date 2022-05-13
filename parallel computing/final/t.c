#include <stdio.h>
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
    int * A, * B;
    // if(!my_rank)
    // {
    //     A = malloc(4 * sizeof(int));
    //     *A = 1; A[1] = 8; A[2] = 9; A[3] = 8;
    // }
    // int buf[] = {0, 0, 8, 8};
    // B = buf;
    // MPI_Bcast(B, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Allgather(&((int){0,0,8,8}), 1, MPI_INT, B, 1, MPI_COMM_WORLD);
    MPI_Allgather((int (*)[4]){0,0,8,8}, 1, MPI_INT, B, 1, MPI_INT, MPI_COMM_WORLD);
    MPI_Finalize();
    printf("my_rank = %d\n", my_rank);
    print(B, 4);
}