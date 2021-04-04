#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 3
#define M 3
#define L 3

double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

pthread_t threads[N];

void *matrixMult(void *arg);

int main()
{
    srand(time(NULL));

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

    for (int i = 0; i < N; i++)
    {
        int *tempPtr = (int *)malloc(sizeof(int));
        *tempPtr = i;
        pthread_create(&threads[i], NULL, matrixMult, tempPtr);
        
    }

    for (int i = 0; i < N; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

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

void *matrixMult(void *arg)
{
    printf("Thread %d of iter %d\n", (int)pthread_self(), *(int *)arg);
    int i = *(int *)arg;
    for (int j = 0; j < L; j++)
    {
        double temp = 0;
        for (int k = 0; k < M; k++)
        {
            temp += matrixA[i][k] * matrixB[k][j];
                printf("(matrixA: %.2f * matrixB: %.2f) = %.2f ",matrixA[i][k], matrixB[k][j], matrixA[i][k] * matrixB[k][j]);
        }
        matrixC[i][j] = temp;
        printf("Total: %.2f\n",temp);
    }
}
