/*
* NAME: Raymond Shum
* DATE: March 16, 2021
* TITLE: Lab 3 - Part 1 - C Program with pipe IPC
* DESCRIPTION: This program initializes a file descriptor
* for I/O and creates 2 child processes. The first process
* duplicates downstream into STDIN while the second process
* duplicates upstream into STDOUT. The first process executes
* the "ls" command and exits, while the second process
* executes "more" on the other end of the pipe and exits. The
* parent process waits for both children to finish and exits.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//main
int main()
{
    int fds[2];
    pipe(fds);
    /*child 1 duplicates downstream into stdin */
    if (fork() == 0)
    {
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("more", "more", NULL);
    }
    /*child 2 duplicates upstream into stdout */
    else if (fork() == 0)
    {
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("ls", "ls", NULL);
    }
    else
    { /*parent closes both ends and wait for children*/
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}