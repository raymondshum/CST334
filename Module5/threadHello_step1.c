/*
* NAME: Raymond Shum
* DATE: April 6, 2021
* TITLE: Lab 5 - Part 1 - "Broken" Multi-threaded Program
* DESCRIPTION: This program creates 10 threads that each
* output their thread and (loop) iteration numbers to
* STDOUT. The output is not as expected due to the address
* (argument) passed to the thread creation function.
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main()
{
    int i;

    for (i = 0; i < NTHREADS; i++)
        pthread_create(&threads[i], NULL, go, &i);

    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

    printf("Main thread done.\n");
    return 0;
}

// I included the address of arg in the printf statement to show the cause of the error
void *go(void *arg)
{
    printf("[0x%X] Hello from thread %d with iteration %d\n", arg, (int)pthread_self(), *(int *)arg);
    return 0;
}
