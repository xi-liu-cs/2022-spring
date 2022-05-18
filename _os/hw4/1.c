#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

    int i = 0; 

    /* ADD SOME THINGS HERE */
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t c = PTHREAD_COND_INITIALIZER;

    void thread_exit() 
    {
        pthread_mutex_lock(&m);
        i = 1;
        pthread_cond_signal(&c);
        pthread_mutex_unlock(&m);
    }

    void
    *foo(void *arg)
    {
        printf("I am foo!!!\n");
        /* ADD SOME CODE HERE */
        thread_exit();
        return NULL;
    }

    void
    *boo(void *arg)
    {
        /* ADD SOME CODE HERE */
        pthread_mutex_lock(&m);
        while(i == 0)
        {
            pthread_cond_wait(&c, &m);
        }
        pthread_mutex_unlock(&m);
        printf("I am boo!!!\n");
    }

    int
    main(int argc, char** argv)
    {
        pthread_t p1, p2;
        pthread_create(&p1, NULL, &foo, NULL);
        pthread_create(&p2, NULL, &boo, NULL);

        // wait for threads to finish
        // before exiting
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
        printf("main: end\n");
        exit(0);
    }