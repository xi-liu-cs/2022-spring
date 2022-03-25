#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mpi.h>

int main()
{
    int my_rank, comm_sz, buf_sz = 20;
    /* buf_sz cannot be initialized as 0,
    then mpi_recv(buf, buf_sz) receive no element */
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

    int start = 2, end = 100, n = end - start + 1, n_proc = 10, 
    loc_n = (my_rank == comm_sz - 1) ? n % n_proc : ceil(n / n_proc); 
    int * a = 0;
    int recvbuf[loc_n];

    if(!my_rank)
    {
        a = malloc(n * sizeof(int));
        for(int i = 0; i < n; ++i)
            a[i] = start + i;
        MPI_Scatter(a, loc_n, MPI_INT, recvbuf, loc_n, 
        MPI_INT, 0, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Scatter(a, loc_n, MPI_INT, recvbuf, loc_n,
        MPI_INT, 0, MPI_COMM_WORLD);
        for(int i = 0; i < loc_n; ++i)
            printf("%d ", recvbuf[i]);
    }
}