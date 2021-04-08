/*
* NAME: Raymond Shum
* DATE: March 30, 2021
* TITLE: Lab 6 - Part 2 - Consumer-Producer Solution
* DESCRIPTION: This is a solution to the consumer-
* producer problem. There are two threads, one consumer
* and one producer, with access to critical sections
* controlled by semaphores. The producer thread waits
* on "empty" and signals "full". The consumer thread
* waits on "full" and signals "empty". Put() and get()
* are critical sections controlled by the mutex 
* semaphore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 

# define NTHREADS 1             // One thread each for producer and consumer.
# define ALPHABET 26            // Number of letters in the alphabet.
# define ANSI_VALUE 97          // The starting ANSI value of 'a'.
# define BUFFER 1               // The size of the shared buffer.

pthread_t proThreads[NTHREADS]; // Array to hold producer threads.
pthread_t conThreads[NTHREADS]; // Array to hold consumer threads.
sem_t empty, full, mutex;       // Semaphores used to support concurrency.

char letter[ALPHABET];          // Array to hold char 'a' to 'z'.
char buffer[BUFFER];            // Shared buffer for producer and consumer threads.

static int position = 0;        // int to track current letter in letter[].
static int fill = 0;            // int to track how full a buffer is.
static int use = 0;             // int to track how empty a buffer is.
static char sentinel = ' ';     // Sentinel value used to track end of data.

void initLetter();
void initResults();
void printArray(char arg[]);
void *producer(void *arg);
void *consumer(void *arg);
void put(char arg);
char get();

int main(){

    // Initialize semaphores to lab specified values.
    sem_init(&empty, 0, BUFFER);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    
    // Initialize letter[].
    initLetter();

    int i = 0;

    // Create producer threads with *producer() startup routine.
    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&proThreads[i], NULL, producer, &i);
    }
    
    // Create consumer threads with *consumer() startup routine.
    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&conThreads[i], NULL, consumer, &i);
    }

    // Join producer threads.
    for (i = 0; i < NTHREADS; i++ ){
        pthread_join(proThreads[i], NULL);
    }

    // Join consumer threads.
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(conThreads[i], NULL);
    }

    printf("Program Completed.\n");

    // Cleanup semaphores.
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

/**
 * Assigns char 'a' to 'z' to letter[0] to letter[25] and prints the array.
 */
void initLetter(){
    
    int charValue = 0;

    for(char c = 'a'; c <= 'z'; c++) {
        charValue = c % ANSI_VALUE;
        letter[charValue] = c;
    }

    printf("Contents of Letter Array: ");
    printArray(letter);
}

/**
 * Prints the content of the array passed as arg[].
 */
void printArray(char arg[]){
    for(int i = 0; i < ALPHABET; i++) {
        printf("%c ", arg[i]);
    }
    printf("\n");
}

/**
 * Waits for consumer to signal empty and for mutex lock to be released. Acquires
 * lock and places the next letter in the buffer and iterates position. Then
 * releases lock and signals full. Returns once the last value of alphabet[] has 
 * been placed in the buffer.
 */
void *producer(void *arg){

    do {
        sem_wait(&empty);
        sem_wait(&mutex);
        put(letter[position++]);
        sem_post(&mutex);
        sem_post(&full);
    } while(position < ALPHABET);

    printf("Producer thread %d:: Ended\n", (int)pthread_self());

    return (NULL);
}

/**
 * Waits for producer to signal full and for mutex lock to be released. Acquires
 * lock and retrieves the next letter from the buffer and prints it to screen. Then
 * releases lock and signals empty. Returns once the last value of alphabet[] has 
 * been retrived from the buffer.
 */
void *consumer(void *arg){
    do {
        sem_wait(&full);
        sem_wait(&mutex);
        sentinel = get();   
        sem_post(&mutex);
        sem_post(&empty);
    } while(sentinel < 'z');

    printf("Consumer thread %d:: Ended\n", (int)pthread_self());

    return (NULL);
}

/**
 * Used by producer to place values in the shared buffer. Places values
 * at buffer[0] to buffer[BUFFER - 1] and loops back to buffer[0].
 */
void put(char arg) {
    buffer[fill] = arg;
    fill = (fill + 1) % BUFFER;
    printf("Producer thread %d:: %c >> buffer\n", 
        (int)pthread_self(), arg);
}

/**
 * Used by consumer to retrieve values from shared buffer. Retrieves
 * values from buffer[0] to buffer[BUFFER - 1] and loops back to
 * buffer[0]. Values are retrieved in FIFO order.
 */
char get() {
    char tmp = buffer[use];
    use = (use + 1) % BUFFER;
    printf("Consumer thread %d:: buffer >> %c\n", 
        (int)pthread_self(), tmp);
    return tmp;
}