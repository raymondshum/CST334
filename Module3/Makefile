# ########################################################
# NAME: Raymond Shum                                     #    
# DATE: March 23, 2021                                   #    
# TITLE: Lab 3 - Part 2 & 5 & 8- Makefile                #    
# DESCRIPTION: This is the Makefile for three programs   # 
# in Lab 3.                                              #
# ########################################################

CC = g++

CFLAGS = -D DEBUG

all: 1_lab3_1.o 4_lab3_2.o 7_lab3_3.o

1_lab3_1.o : 1_lab3_1.c
	gcc $(CFLAGS) -o 1_lab3_1.o 1_lab3_1.c

4_lab3_2.o : 4_lab3_2.c
	gcc $(CFLAGS) -o 4_lab3_2.o 4_lab3_2.c

7_lab3_3.o : 7_lab3_3.c
	gcc $(CFLAGS) -o 7_lab3_3.o 7_lab3_3.c

clean:
	rm -f 1_lab3_1.o 4_lab3_2.o 7_lab3_3.o
