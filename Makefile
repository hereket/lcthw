CC=gcc
CFLAGS=-Wall -g
SOURCES=ex1.c
OBJECTS=$(SOURCES:.c=.o)


all: 
	$(CC) $(CFLAGS) -o ex17 ex17.c

clean:
	rm -f test ex17
