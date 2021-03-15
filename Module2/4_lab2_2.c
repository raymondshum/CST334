/*
* NAME: Raymond Shum
* DATE: March 16, 2021
* TITLE: Lab 3 - Part 4 - Revise C Code for Demonstration
* DESCRIPTION: This program creates a child process, which
* executes the Linux shell command "ls", The parent process
* waits for the child to complete before exiting. Intended
* microsecond delay is passed as a command line argument.
*/

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
    int i, n; // n microseconds to input from keyboard for delay

    //Checks to see if a command-line argument has been passed
    if(argc != 2)
    {
        //Microsecond delay is set to 0 if no argument is passed.
        printf("Error: No value for milisecond delay has been passed as a command-line argument.");
        printf(" Defaulting to a value of 0.");
        n = 0;
    }
    else
    {
        //Microsecond delay is set to value of argument if one has been passed.
        n = atoi(argv[1]);
    }

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
