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
            printf("%.2f ", matrixB[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++) {
        int *ptr = malloc(sizeof(int));
        *ptr = i;
        pthread_create(&threads[i], NULL, matrixMult, ptr);
    }

    for (int i = 0; i < N; i++) {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *matrixMult(void *arg){
    printf("Thread %d of iter %d\n", (int)pthread_self(), *(int *)arg);
}
