/*Sample C program for Lab assignment 1*/

#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
#include <sys/wait.h>  /* wait */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[])
{
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");

    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }

    return 0;
}
