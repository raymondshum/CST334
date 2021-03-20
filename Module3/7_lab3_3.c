/*
* NAME: Raymond Shum
* DATE: March 16, 2021
* TITLE: Lab 3 - Part 7 - C Program with pipe IPC
* DESCRIPTION: This program implements the command:
* cat /etc/passwd | grep "root". The second child
* process writes the contents of the cat command
* into its end of the pipe and the first child
* reads these contents as input. It then feeds the
* input into the grep command.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

    int fds[2];
    pipe(fds);
    /*child 1 duplicates downstream into stdin */
    if (fork() == 0)
    {
        dup2(fds[0], 0);
        close(fds[1]);
        execlp("/bin/grep", "grep", "root", NULL);
    }
    /*child 2 duplicates upstream into stdout */
    else if (fork() == 0)
    {
        dup2(fds[1], 1);
        close(fds[0]);
        execlp("/bin/cat", "cat", "/etc/passwd", NULL);
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