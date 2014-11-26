CC=gcc
CFLAGS=-Wall -g
SOURCES=ex1.c
OBJECTS=$(SOURCES:.c=.o)


all: 
	$(CC) $(CFLAGS) -o ex16 ex16.c

clean:
	rm -f test ex16
