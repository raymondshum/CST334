CC = g++

CFLAGS = -D DEBUG

all: 1_fifo.o queue_test.o

1_fifo.o : 1_fifo.c
	gcc $(CFLAGS) -o 1_fifo.o 1_fifo.c

queue_test.o : queue_test.c
	gcc $(CFLAGS) -o queue_test.o queue_test.c


clean:
	rm -f 1_fifo.o queue_test.o
