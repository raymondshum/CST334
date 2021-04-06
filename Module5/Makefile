# ########################################################
# NAME: Raymond Shum                                     #
# DATE: April 6, 2021                                    #
# TITLE: Lab 5 - Part 2 - Makefile                       #
# DESCRIPTION: This is the Makefile for three programs   #
# in Lab 5.                                              #
# ########################################################

CC = g++

CFLAGS = -D DEBUG -Wall -pthread

all: threadHello_step1.o threadHelloFixed_step1_Fixed.o matrix_multiplication.o matrix_multiplication_test.o

threadHello_step1.o : threadHello_step1.c
	gcc $(CFLAGS) -o threadHello_step1.o threadHello_step1.c

threadHelloFixed_step1_Fixed.o : threadHelloFixed_step1_Fixed.c
	gcc $(CFLAGS) -o threadHelloFixed_step1_Fixed.o threadHelloFixed_step1_Fixed.c

matrix_multiplication_test.o : matrix_multiplication_test.c
	gcc $(CFLAGS) -o matrix_multiplication_test.o matrix_multiplication_test.c

matrix_multiplication.o : matrix_multiplication.c
	gcc $(CFLAGS) -o matrix_multiplication.o matrix_multiplication.c

clean:
	rm -f threadHello_step1.o threadHelloFixed_step1_Fixed.o matrix_multiplication.o matrix_multiplication_test.o
