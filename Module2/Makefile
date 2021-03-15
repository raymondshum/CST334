# ########################################################
# NAME: Raymond Shum                                     #    
# DATE: March 16, 2021                                   #    
# TITLE: Lab 3 - Part 2 & 5 - Makefile                   #    
# DESCRIPTION: This is the Makefile for both programs in #     
# Lab 3.                                                 #
# ########################################################

CC = g++

CFLAGS = -D DEBUG

all: 1_lab2_1 4_lab2_2

1_lab2_1 : 1_lab2_1.c
	gcc $(CFLAGS) -o 1_lab2_1 1_lab2_1.c

4_lab2_2 : 4_lab2_2.c
	gcc $(CFLAGS) -o 4_lab2_2 4_lab2_2.c

clean:
	rm -f 1_lab2_1 4_lab2_2
