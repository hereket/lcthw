CC=gcc
CFLAGS=-Wall -g
SOURCES=ex1.c
OBJECTS=$(SOURCES:.c=.o)


all: 
	$(CC) $(CFLAGS) -o ex18 ex18.c

clean:
	rm -f test ex18
