#include <stdio.h>
#include <string.h>
#include <mpi.h>

// https://www.codingame.com/playgrounds/349/introduction-to-mpi/hello-world

const int MAX_STRING = 100;

int main()
{
    char greet[MAX_STRING];
    int comm_size; /* num processes */
    int my_rank; 

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank)
    {
        sprintf(greet, "greet from process %d of %d",
        my_rank, comm_size);
        MPI_Send(greet, strlen(greet) + 1, MPI_CHAR,
        0, 0, MPI_COMM_WORLD);
    }
    else
    {
        printf("greet from process %d of %d\n", my_rank, comm_size);
        for(int i = 1; i < comm_size; i++)
        {
            MPI_Recv(greet, MAX_STRING, MPI_CHAR,
            i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s\n", greet);
        }   
    }

    MPI_Finalize();
    return 0;
}