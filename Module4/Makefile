# ########################################################
# NAME: Raymond Shum                                     #    
# DATE: March 30, 2021                                   #    
# TITLE: Lab 4 - Part 1 & 3  Makefile                    #    
# DESCRIPTION: This is the Makefile for two programs     # 
# in Lab 4.                                              #
# ########################################################

CC = g++

CFLAGS = -D DEBUG 

all: 1_fifo.o queue_test.o

1_fifo.o : 1_fifo.c
	gcc $(CFLAGS) -o 1_fifo.o 1_fifo.c queue.c node.c

queue_test.o : queue_test.c
	gcc $(CFLAGS) -o queue_test.o queue_test.c queue.c node.c


clean:
	rm -f 1_fifo.o queue_test.o