# CST 334 - Operating Systems
Description taken from student course catalog. Students in this course will learn about the use and design of modern operating systems, focusing on Linux. On the “use” side, students will learn the Linux command line, to write shell scripts, and to build programs with GNU utilities like awk, sed, and make. On the “design” side, students will develop a deep understanding of process management, memory management, file systems, and concurrency, and how they apply to modern technologies like virtualization and cloud computing.

## Contents

[Lab Descriptions](#lab-descriptions)

[Module 1](#module-1)

[Module 2](#module-2)


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
