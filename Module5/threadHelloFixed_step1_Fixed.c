#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main()
{
    int i;
    int *array[NTHREADS];


    for (i = 0; i < NTHREADS; i++)
    {
        int *tempPtr = (int *) malloc(sizeof(int));
        *tempPtr = i;
        array[i] = tempPtr;

        pthread_create(&threads[i], NULL, go, array[i]);
    }

    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

     for (i = 0; i < NTHREADS; i++)
     {
         free(array[i]);
     }

    printf("Main thread done.\n");
    return 0;
}

void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
    return 0;
}
