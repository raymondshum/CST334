/*
* NAME: Raymond Shum
* DATE: March 30, 2021
* TITLE: Lab 4 - Part 1 - FIFO Page Replacement Program
* DESCRIPTION: This program simulates the FIFO page replacement
* algorithm, using a linked list as a cache. It takes a command
* line argument that determines the size of the cache. It uses
* accesses.txt as a source of input that determines the order in
* which pages are being accessed. Each integer in accesses.txt
* represents a page number, which is checked against the linked
* list (pageQueue). If the integer is not present, a miss counter
* is incremented and the FIFO page replacement algorithm is
* executed. If it is a hit, the hit counter is incremented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "queue.h"
#include "node.h"

typedef struct
{ //to
    int pageno;
} ref_page;

int main(int argc, char *argv[])
{
    struct queue *pageQueue = queue_create(); // FIFO page queue
    struct node *pageResult = NULL;           // Holds node if pageNumber is found in PageQueue and NULL if not

    int C_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[C_SIZE];     // Cache that stores pages
    char pageCache[100];        // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int queueSize = 0;   // keeps track of queue size to avoid calling queue_length in a loop
    int hit = 0;         // keeps track of hits for end of run statistics

    for (i = 0; i < C_SIZE; i++)
    { //initialise cache array
        cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin))
    {
        int page_num = atoi(pageCache); //Stores number read from file as int
        pageResult = queue_find(pageQueue, page_num); // Tries to find page_num in pageQueue

        // If queue is empty, store the new page (as head)
        if (queueSize == 0)
        {
            enqueue(pageQueue, page_num);
            queueSize++;
            totalFaults++;
        }
        // If page is not found and queue is not full, store the new page (at end)
        else if (pageResult == NULL && queueSize < C_SIZE)
        {
            enqueue(pageQueue, page_num);
            queueSize++;
            totalFaults++;
        }
        // If page is not found and queue is full, dequeue the first page (at head) and store the new page (at end)
        else if (pageResult == NULL && queueSize == C_SIZE)
        {
            dequeue(pageQueue);
            enqueue(pageQueue, page_num);
            totalFaults++;
        }
        else
        {
            hit++;
        }
    }

    // End of run statistics
    double percentFault = ((double)totalFaults/((double)totalFaults+(double)hit)*100);
    printf("%d Total hits\n", hit);
    printf("%d Total Page Faults", totalFaults);
    printf("\n%.2f%% Fault Rate", percentFault);
    printf("\nQueue Size: %d\n\n", queue_length(pageQueue));

    // Free memory for queue and node
    queue_destroy(pageQueue);
    destroyNode(pageResult);

    return 0;
}