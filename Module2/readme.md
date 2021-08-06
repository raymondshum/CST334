# Lab 2 - Process Execution

---

## Instructions

Open a bash terminal in this folder and enter: <code>./run.sh</code>

You may have to set permissions using: <code>chmod 774 run.sh</code>

You do not necessarily need to use that command, but you will need to set the execute bit.

Requires: [GCC](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/) 

---

## Description

This assignment focuses on demonstrating knowledge of C programming in a Linux environment. The aim of the lab was to develop knowledge for implementing programs with two or more processes using the following system calls: fork(), exit(), wait(), and exec(). 

The first program takes an argument specifying delay in milliseconds. It creates a child process using fork(). Both the parent and child process iterate from 0 to 99, printing the results. The lab has us note our observations regarding the interaction between delay, parent and child processes.

The second program also takes an argument specifying delay in milliseconds and creates a child process using fork(). This time, the child process will perform the "ls" UNIX command using execlp(). The parent process will wait() until the child finishes, printing results to screen. We also note our observations regarding the determinism of this program.

---


## Screen Shots

### _Program 1_

Please refer to the run [output](/Module2/3_run1.txt).

### _Program 2_
![run](/Module2/6_run2.PNG)

---

[Return to Main Page](https://github.com/raymondshum/CST334)
