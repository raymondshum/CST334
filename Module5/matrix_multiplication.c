#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// dimensions used by matrixes
#define N 3
#define M 3
#define L 3

// declare matrixes as global variables
// matrixA * matrixB = matrixC
double matrixA[N][M]; 
double matrixB[M][L];
double matrixC[N][L];

// # threads equals number rows of matrixA
pthread_t threads[N];

// prototype of the thread multiplication function
void *matrixMult(void *arg); 

int main()
{
    srand(time(NULL));

    // seed matrixA with random numbers between 0-10 and print
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrixA[i][j] = rand() % 10;
            printf("%.2f ", matrixA[i][j]);
        }
        printf("\n");
    }

    // seed matrixB with random numbers between 0-10 and print
    printf("\nMatrix B:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < L; j++)
        {
            matrixB[i][j] = rand() % 10;
            printf("%.2f ", matrixB[i][j], i, j);
        }
        printf("\n");
    }

    // Create 1 thread per row of matrixA.
    // Each thread will multiply its row of matrixA by the
    // column of matrixB.
    for (int i = 0; i < N; i++)
    {
        int *tempPtr = (int *)malloc(sizeof(int));
        *tempPtr = i;
        pthread_create(&threads[i], NULL, matrixMult, tempPtr);
        
    }

    // Wait for all threads to return.
    for (int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Display the results of matrixC
    printf("\nMatrix C:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < L; j++)
        {
            printf("%.2f ", matrixC[i][j], i, j);
        }
        printf("\n");
    }

    return 0;
}

// Multiplies a row of matrixA with a column of matrixB and assigns the results to
// the corresponding cell in matrixC
void *matrixMult(void *arg)
{
    int i = *(int *)arg;
    for (int j = 0; j < L; j++)
    {
        double temp = 0;
        for (int k = 0; k < M; k++)
        {
            temp += matrixA[i][k] * matrixB[k][j];

            printf("\n(A[%d][%d]: %.2f * B[%d][%d]: %.2f) = %.2f ",
                i, k, matrixA[i][k], 
                k, j, matrixB[k][j],
                matrixA[i][k] * matrixB[k][j]);
        }

        matrixC[i][j] = temp;
        printf("\nC[%d][%d] = %.2f\n", i, j, temp);
    }
}
