/*
* NAME: Raymond Shum
* DATE: April 6, 2021
* TITLE: Lab 5 - Part 1 - "Fixed" Multi-threaded Program
* Description: This program is the "fixed" version of the
* multi-threaded program "threadHello_step1.c". It passes
* a heap-allocated integer pointer to the thread created
* argument rather than the stack-allocated address of the
* local integer variable that was passed in the original
* source code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main()
{
    int i;
    int *array[NTHREADS]; // assign an array of integer pointers

    // create number of threads specified by NTHREADS
    for (i = 0; i < NTHREADS; i++)
    {
        // allocate memory for an integer pointer and assign to array
        int *tempPtr = (int *) malloc(sizeof(int));
        *tempPtr = i;
        array[i] = tempPtr;

        // create a thread with "go" as the starting routine
        // the value of *tempPtr, stored in array[i] is passed as an argument
        pthread_create(&threads[i], NULL, go, array[i]);
    }

    // wait for all threads to return
    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

    // free all pointers stored in array[]
     for (i = 0; i < NTHREADS; i++)
     {
         free(array[i]);
     }

    printf("Main thread done.\n");
    return 0;
}

// each thread prints the address of arg, its threadID and the iteration# of the loop where it was created
void *go(void *arg)
{
    printf("[%p] Hello from thread %d with iteration %d\n", (int *)arg, (int)pthread_self(), *(int *)arg);
    return 0;
}
