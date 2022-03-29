#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>

// must compile with: mpicc  -std=c99 -Wall -o checkdiv 

int main(int argc, char *argv[]){
  
unsigned int x, A, B;
unsigned int i; //loop index
FILE * fp; //for creating the output file
char filename[100] = ""; // the file name
char * numbers; //the numbers in the range [2, N]

double start_p1, end_p1, start_p2, end_p2;
double time_for_p1; 



/////////////////////////////////////////


start_p1 = clock();
// Check that the input from the user is correct.
if(argc != 4){

  printf("usage:  ./checkdiv A B x\n");
  printf("A: the lower bound of the range [A,B]\n");
  printf("B: the upper bound of the range [A,B]\n");
  printf("x: divisor\n");
  exit(1);
}  

A = (unsigned int)atoi(argv[1]); 
B = (unsigned int)atoi(argv[2]); 
x = (unsigned int)atoi(argv[3]);
 

// The arguments to the main() function are available to all processes and no need to send them from process 0.
// Other processes must, after receiving the variables, calculate their own range.


/////////////////////////////////////////


/////////////////////////////////////////
//start of part 1
start_p1 = MPI_Wtime();
// The main computation part starts here
int my_rank, comm_sz;
MPI_Init(NULL, NULL);
MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

unsigned int n = B - A + 1, loc_n = n / comm_sz, 
loc_a, loc_b, retcount, send_i;
unsigned int * sendbuf;

loc_a = A + my_rank * loc_n;
loc_b = loc_a + loc_n - 1;
if(my_rank == comm_sz - 1)
{
    loc_b = B;
    loc_n = loc_b - loc_a + 1;
}
/* find numbers divisible by x */

sendbuf = malloc(n * sizeof(unsigned int));
send_i = 0;
unsigned int start;
for(unsigned int i = loc_a; i <= loc_b; ++i)
{
    if(!(i % x))
    {
        start = i;
        break;
    }
}
for(unsigned int i = start; i <= loc_b; i += x)
    sendbuf[send_i++] = i;

/* gatherv */
unsigned int * recvbuf;

if(!my_rank)
    recvbuf = malloc(n * sizeof(unsigned int));

unsigned recvcount = send_i + n % loc_n;
MPI_Gather(sendbuf, send_i, MPI_UNSIGNED, recvbuf, recvcount, MPI_UNSIGNED, 0, MPI_COMM_WORLD);

int end;
for(int i = B; i >= 0; --i)
{
    if(!(i % x))
    {
        end = i;
        break;
    }
}
if(!my_rank)
{
  for(int i = 0; i != end; ++i)
    if(recvbuf[i])
        printf("i = %d, r = %u\n", i, recvbuf[i]);
  printf("\n");
}
  
// end of the main compuation part
end_p1 = MPI_Wtime();
// Use reduction operation to get MAX of (end_p1 - start_p1) among processes 
// and send it to process 0 as time_for_p1
int loc_p1 = end_p1 - start_p1;
MPI_Reduce(&loc_p1, &time_for_p1, 1,
MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
//end of part 1
/////////////////////////////////////////


/////////////////////////////////////////
//start of part 2
// Writing the results in the file
if(!my_rank)
{
  //forming the filename

  start_p2 = MPI_Wtime();

  strcpy(filename, argv[2]);
  strcat(filename, ".txt");

  if( !(fp = fopen(filename,"w+t")))
  {
    printf("Cannot create file %s\n", filename);
    exit(1);
  }

  for(int i = 0; i != end; ++i)
    if(recvbuf[i])
        fprintf(fp, "%d\n", recvbuf[i]);
  //Write the numbers divisible by x in the file as indicated in the lab description.
}
fclose(fp);
end_p2 = MPI_Wtime();
MPI_Finalize();
//end of part 2
/////////////////////////////////////////

/* Print  the times of the three parts */
printf("time of part1 = %lf s    part2 = %lf s\n", 
       (double)(time_for_p1),
       (double)(end_p2-start_p2) );
return 0;
}

