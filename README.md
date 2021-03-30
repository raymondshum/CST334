# CST 334 - Operating Systems
Description taken from student course catalog. Students in this course will learn about the use and design of modern operating systems, focusing on Linux. On the “use” side, students will learn the Linux command line, to write shell scripts, and to build programs with GNU utilities like awk, sed, and make. On the “design” side, students will develop a deep understanding of process management, memory management, file systems, and concurrency, and how they apply to modern technologies like virtualization and cloud computing.

## Contents

[Lab Descriptions](#lab-descriptions)

[Module 1](#module-1)

[Module 2](#module-2)

[Module 3](#module-3)

[Module 4](#module-4)

## Lab Descriptions
These projects are the primary deliverables associated with the CSUMB's Spring 2021 section of CST 334. They are assigned 1 per week (as modules) and meant to be the practical demonstration of the core competencies of that week's course materials.

[Return to Top](#contents)

### Module 1
For this exercise, we focused on learning the fundamentals of navigating a Linux shell and implemented our knowledge through the creation of a simple bash script. The script performs simple user verification by checking the currently logged in user against a pre-declared eligible user. If the user is allowed to procede, they are asked to input three integer values. These integer values are used to calculate the areas of a rectangle and circle, respectively. The calculated values are echoed back to the user.

[Return to Top](#contents)

### Module 2
This assignment focuses on demonstrating knowledge of C programming in a Linux environment. The aim of the lab was to develop knowledge for implementing programs with two or more processes using the following system calls: fork(), exit(), wait(), and exec(). 

The first program takes an argument specifying delay in milliseconds. It creates a child process using fork(). Both the parent and child process iterate from 0 to 99, printing the results. The lab has us note our observations regarding the interaction between delay, parent and child processes.

The second program also takes an argument specifying delay in milliseconds and creates a child process using fork(). This time, the child process will perform the "ls" UNIX command using execlp(). The parent process will wait() until the child finishes, printing results to screen. We also note our observations regarding the determinism of this program.

[Return to Top](#contents)

### Module 3

This project was executed in 3 phases.

Program 1: Implements the Linux shell command: "ls | more". The program creates two child processes. The first child executes the "more" command downstream of the pipe and the second child executes "ls" upstream of the pipe. Both children close their ends of the pipe. The parent process closes both ends of the pipe and waits for both children to finish.

(Need confirmation) Program 2: A command line argument is passed through the argv[] of main(). The parent process creates two children. The first child (upstream of the pipe) writes the number of arguments passed and the contents of the arguments. The second child (downstream of the pipe) reads the arguments from stdin and writes the contents.

Program 3: This program implements the command "cat /etc/passwd | grep root" in the style of Program 1.

[Return to Top](#contents)

### Module 4

This program is meant to be a simulation of a FIFO page replacement algorithm used by a cache (such as a TLB) to determine the method of page replacement in the event of a full cache. The cache is represented by the "pageQueue" linked list, with its predetermined size passed as a command line argument. The "accesses.txt" text file holds 1001 non-unique integer entries meant to represent requests made to the cache to check for presence of respective pages. Each integer is passed as input to the program, which first checks the cache to see if the page is present in physical memory and performs the following actions based on the results:

If the cache is either empty or not full and the page is not found, then the page is added to the end of the list and a page fault counter is incremented. If the page is not found and the cache is full, then the head of the linked list (oldest entry) is dequeued. The new page is subsequently enqueued at the end as the newest entry. If the page is found, then the hit counter is incremented and the linked list is not changed.

The write-up (analysis of results) is present as a .pdf file in the Module4 folder.

[Return to Top](#contents)
