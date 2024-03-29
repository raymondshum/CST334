#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define PRO_THREAD 10
#define CON_THREAD 10
#define ALPHABET 26
#define ANSI_VALUE 97
#define BUFFER 26

pthread_t proThreads[PRO_THREAD];
pthread_t conThreads[CON_THREAD];
sem_t empty, full, mutex;

char letter[ALPHABET];
char buffer[BUFFER];

static int position = 0;
static int fill = 0;
static int use = 0;
static int consumed = 0;

void initLetter();
void initResults();
void printArray(char arg[]);
void *producer(void *arg);
void *consumer(void *arg);
void put(char arg);
char get();

int main()
{
    sem_init(&empty, 0, BUFFER);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    initLetter();

    int i = 0;

    for (i = 0; i < PRO_THREAD; i++)
    {
        pthread_create(&proThreads[i], NULL, producer, &i);
    }

    for (i = 0; i < CON_THREAD; i++)
    {
        pthread_create(&conThreads[i], NULL, consumer, &i);
    }

    for (i = 0; i < PRO_THREAD; i++)
    {
        pthread_join(proThreads[i], NULL);
    }

    for (i = 0; i < CON_THREAD; i++)
    {
        pthread_join(conThreads[i], NULL);
    }

    printf("Program Completed.\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}

void initLetter()
{

    int charValue = 0;

    for (char c = 'a'; c <= 'z'; c++)
    {
        charValue = c % ANSI_VALUE;
        letter[charValue] = c;
    }

    printf("Contents of Letter Array: ");
    printArray(letter);
}

void printArray(char arg[])
{
    for (int i = 0; i < ALPHABET; i++)
    {
        printf("%c ", arg[i]);
    }
    printf("\n");
}

void *producer(void *arg)
{

    do
    {
        while (sem_trywait(&empty) != 0)
        {
            if (position == (ALPHABET))
            {
                printf("Producer thread %d:: Ended (Sentinel)\n", (int)pthread_self());
                return (NULL);
            }
        }
        sem_wait(&mutex);

        if (position < ALPHABET)
            put(letter[position++]);

        sem_post(&mutex);
        sem_post(&full);
    } while (position < ALPHABET);

    printf("Producer thread %d:: Ended\n", (int)pthread_self());

    return (NULL);
}

void *consumer(void *arg)
{

    do
    {
        while (sem_trywait(&full) != 0)
        {
            if (consumed >= ALPHABET)
            {
                printf("Consumer thread %d:: Ended (Sentinel)\n", (int)pthread_self());
                return (NULL);
            }
        }
        sem_wait(&mutex);
        if (consumed < ALPHABET)
        {
            get();
            consumed++;
        }
        sem_post(&mutex);
        sem_post(&empty);

    } while (consumed <= ALPHABET);

    printf("Consumer thread %d:: Ended\n", (int)pthread_self());

    return (NULL);
}

void put(char arg)
{
    buffer[fill] = arg;
    fill = (fill + 1) % BUFFER;
    printf("Producer thread %d:: %c >> buffer\n",
           (int)pthread_self(), arg);
}

char get()
{
    char tmp = buffer[use];
    use = (use + 1) % BUFFER;
    printf("Consumer thread %d:: buffer >> %c\n",
           (int)pthread_self(), tmp);
    return tmp;
}