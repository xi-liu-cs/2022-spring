#include <stdio.h>
#include <mpi.h>

int main(int argc, char ** argv)
{
    int comm_sz, /* num processes */
    my_rank;
    MPI_Init(&argc , &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    /* exam2-sp20.1 */
    int x, y, z; 
    MPI_Comm COMM; 
    int new_rank; 
    MPI_Comm_split(MPI_COMM_WORLD, my_rank % 2, my_rank, &COMM); 
    MPI_Comm_rank(COMM, &new_rank); 
    switch(new_rank) 
    { 
        case 0: 
            x=11; y=12; z=10; 
            MPI_Reduce(&x, &y, 1, MPI_INT, MPI_SUM, 0, COMM); 
            MPI_Allreduce(&y, &z, 1, MPI_INT, MPI_SUM, COMM); 
            break; 
        case 1: 
            x=3; y=8; z=5; 
            MPI_Reduce(&x, &z, 1, MPI_INT, MPI_SUM, 0, COMM); 
            MPI_Allreduce(&y, &x, 1, MPI_INT, MPI_SUM, COMM); 
            break; 
        default: 
            x=8; y=9; z=11; 
            MPI_Reduce(&z, &y, 1, MPI_INT, MPI_SUM, 0, COMM); 
            MPI_Allreduce(&x, &y, 1, MPI_INT, MPI_SUM, COMM); 
            MPI_Bcast(&y, 1, MPI_INT, 1, COMM); 
            break; 
    } 
    MPI_Finalize();
    printf("my_rank = %d, x = %d, y = %d, z = %d\n", my_rank, x, y, z);
}

