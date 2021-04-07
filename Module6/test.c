#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 

# define PRO_THREAD 1
# define CON_THREAD 1
# define ALPHABET 26
# define ANSI_VALUE 97
# define BUFFER 1

pthread_t proThreads[PRO_THREAD];
pthread_t conThreads[CON_THREAD];
sem_t empty, full, mutex;

char letter[ALPHABET];
char results[ALPHABET];

void initLetter();
void initResults();
void printArray(char arg[]);
void *producer(void *arg);
void *consumer(void *arg);
void put(void *arg);
char get(void *arg);

int main(){

    sem_init(&empty, 0, BUFFER);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    
    initLetter();
    initResults();

    int i = 0;
    pthread_create(&proThreads[i], NULL, producer, &i);
    pthread_create(&proThreads[i], NULL, consumer, &i);
    pthread_join(proThreads[i], NULL);
    pthread_join(conThreads[i], NULL);

    return 0;
}

void initLetter(){
    
    int charValue = 0;

    for(char c = 'a'; c <= 'z'; c++) {
        charValue = c % ANSI_VALUE;
        letter[charValue] = c;
    }

    printf("Contents of Letter Array: ");
    printArray(letter);

}

void initResults(){
    for(int i = 0; i < ALPHABET; i++){
        results[i] = ' ';
    }

    printf("Contents of Results Array: ");
    printArray(results);
}

void printArray(char arg[]){
    for(int i = 0; i < ALPHABET; i++) {
        printf("%c ", arg[i]);
    }
    printf("\n");
}

void *producer(void *arg){
    
    printf("Producer: %d | Iteration: %d\n", (int)pthread_self(), *(int*)arg);

    return (NULL);
}

void *consumer(void *arg){

        printf("Consumer: %d | Iteration: %d\n", (int)pthread_self(), *(int*)arg);

    return (NULL);
}