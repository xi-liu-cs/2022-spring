#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
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

int n = B - A + 1, loc_n = n / comm_sz, 
offset, retcount, ret_i;
size_t sz = comm_sz * sizeof(int);
int * sendcounts = malloc(sz), * displacements = malloc(sz);
offset = 0;
for(int i = 0; i < comm_sz; ++i)
{
    if(i == comm_sz - 1)
      loc_n = n / comm_sz + n % loc_n;
    displacements[i] = offset;
    offset += loc_n;
    sendcounts[i] = loc_n;
    if(!my_rank)
      printf("sc[%d] = %d\n", i, sendcounts[i]);
}

/* scatterv */
int * sendbuf, * recvbuf, * ret_buf;

if(!my_rank)
{
  sendbuf = malloc(n * sizeof(int));
  for(int i = 0; i < n; ++i)
    sendbuf[i] = A + i;
}

recvbuf = malloc(sendcounts[my_rank] * sizeof(int));
MPI_Scatterv(sendbuf, sendcounts, displacements, MPI_INT,
recvbuf, sendcounts[my_rank], MPI_INT, 0, MPI_COMM_WORLD);

/* find numbers divisible by x */
// int * sendcounts2 = malloc(sz), * displacements2 = malloc(sz);
// int _loc_n = n / comm_sz;

// offset = 0;
// retcount = _loc_n / x;
// if(!my_rank)
// {
//   printf("loc = %d\n", _loc_n);
//   printf("rc = %d\n", retcount);
// }

// for(int i = 0; i < comm_sz; ++i)
// {
//   if(i == comm_sz - 1)
//     sendcounts2[i] = (_loc_n / x) + 1;
//   else
//     sendcounts2[i] = retcount;
//   displacements2[i] = offset;
//   offset += sendcounts2[i];
  // if(!my_rank)
  //   printf("i = %d, s = %d\n", i, sendcounts2[i]);
// }

  // printf("sc[%d] = %d\n",i, sendcounts[my_rank]);
  // printf("locn = %d\n", loc_n);

retcount = loc_n / x;
ret_buf = malloc(retcount * sizeof(int));
ret_i = 0;
for(int i = 0; i < sendcounts[my_rank]; ++i)
  if(!(recvbuf[i] % x))
    ret_buf[ret_i++] = recvbuf[i];
if(my_rank == comm_sz - 1)
    ret_buf[ret_i++] = INT_MIN;
printf("rk = %d, ret = %d\n", my_rank, ret_i);

/* gatherv */
int * sendbuf2, * recvbuf2;

if(!my_rank)
  recvbuf2 = malloc(n / x * sizeof(int));
sendbuf2 = ret_buf;

MPI_Gather(sendbuf2, retcount, MPI_INT, recvbuf2, retcount, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Finalize();

if(!my_rank)
{
  for(int i = 0; recvbuf2[i] != INT_MIN; ++i)
    printf("i = %d, r = %d\n", i, recvbuf2[i]);
  printf("\n");
}
  
// end of the main compuation part
end_p1 = MPI_Wtime();
// Use reduction operation to get MAX of (end_p1 - start_p1) among processes 
// and send it to process 0 as time_for_p1

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

  for(int i = 0; i < n / x; ++i)
    if(recvbuf2[i])
        fprintf(fp, "%d\n", recvbuf2[i]);
  //Write the numbers divisible by x in the file as indicated in the lab description.
}
fclose(fp);

end_p2 = MPI_Wtime();
//end of part 2
/////////////////////////////////////////

/* Print  the times of the three parts */
printf("time of part1 = %lf s    part2 = %lf s\n", 
       (double)(time_for_p1),
       (double)(end_p2-start_p2) );
return 0;
}

