# #########################################################
# NAME: Raymond Shum                                      #
# DATE: Apr 13, 2021                                      #
# TITLE: Lab 5 - Part 2  Makefile                         #
# DESCRIPTION: This is the Makefile for threadSyn.c (the  #
# provided code from the lab) and lab6.c (the solution to #
# the produdcer-consumer problem).                        #
# #########################################################

CC = g++

CFLAGS = -D DEBUG -Wall -pthread

all: threadSyn.o lab6.o

threadSyn.o : threadSyn.c
	gcc $(CFLAGS) -o threadSyn.o threadSyn.c 

lab6.o : lab6.c
	gcc $(CFLAGS) -o lab6.o lab6.c 


clean:
	rm -f threadSyn.o lab6.o