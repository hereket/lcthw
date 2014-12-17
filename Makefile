CFLAGS=-Wall -g 
CC=gcc


all: ex22_main 

ex22_main: ex22.o

clean:
	rm -f ex20
	rm -f *.o
