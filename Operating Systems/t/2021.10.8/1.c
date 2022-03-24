#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

//youtube, what is mutex in C?
int count = 0;

void * funct()
{
    for(int i = 0; i < 1000000; i++)
    {/*
       https://stackoverflow.com/questions/1091099/does-one-assembler-instruction-always-execute-atomically
       movq count, %rax     //load count to a register on cpu
       addq $1, %rax        //add 1 to register
       movq %rax, count     //store the updated register in count
    */
        count = count + 1;
    }
}

int main()
{
    pthread_t p1, p2;
    pthread_create(&p1, NULL, &funct, NULL);
    pthread_create(&p2, NULL, &funct, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("%d", count);
}