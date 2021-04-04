# ########################################################
# NAME: Raymond Shum                                     #
# DATE: March 23, 2021                                   #
# TITLE: Lab 5 - Part 2 - Makefile                       #
# DESCRIPTION: This is the Makefile for three programs   #
# in Lab 5.                                              #
# ########################################################

CC = g++

CFLAGS = -D DEBUG -Wall -pthread

all: threadHello_step1.o threadHelloFixed_step1_Fixed.o

threadHello_step1.o : threadHello_step1.c
	gcc $(CFLAGS) -o threadHello_step1.o threadHello_step1.c

threadHelloFixed_step1_Fixed.o : threadHelloFixed_step1_Fixed.c
	gcc $(CFLAGS) -o threadHelloFixed_step1_Fixed.o threadHelloFixed_step1_Fixed.c

clean:
	rm -f threadHello_step1.o threadHelloFixed_step1_Fixed.o