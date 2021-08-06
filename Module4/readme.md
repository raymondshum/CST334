# Lab 4 - Memory Management
---

## Instructions

Open a bash terminal in this folder and enter: <code>./run.sh</code>

You may have to set permissions using: <code>chmod 774 run.sh</code>

You do not necessarily need to use that command, but you will need to set the execute bit.

Requires: [GCC](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/) 

---

## Description

This program is meant to be a simulation of a FIFO page replacement algorithm used by a cache (such as a TLB) to determine the method of page replacement in the event of a full cache. The cache is represented by the "pageQueue" linked list, with its predetermined size passed as a command line argument. The "accesses.txt" text file holds 1001 non-unique integer entries meant to represent requests made to the cache to check for presence of respective pages. Each integer is passed as input to the program, which first checks the cache to see if the page is present in physical memory and performs the following actions based on the results:

If the cache is either empty or not full and the page is not found, then the page is added to the end of the list and a page fault counter is incremented. If the page is not found and the cache is full, then the head of the linked list (oldest entry) is dequeued. The new page is subsequently enqueued at the end as the newest entry. If the page is found, then the hit counter is incremented and the linked list is not changed.

The write-up (analysis of results) is present as a .pdf file in the Module4 folder.

---

## Documentation

[Lab Write Up](./4_writeup.pdf)

---

[Return to Main Page](https://github.com/raymondshum/CST334)
