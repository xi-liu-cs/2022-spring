#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void * funct()
{
    for(int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex1);
        printf("lock1\n");
        pthread_mutex_lock(&mutex2);
        printf("lock2\n");
        count++;
        pthread_mutex_unlock(&mutex1);
        pthread_mutex_unlock(&mutex2);
    }
    printf("finish\n");
}

int main()
{
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_t p1, p2;
    pthread_create(&p1, NULL, &funct, NULL);
    pthread_create(&p2, NULL, &funct, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("%d", count);
}