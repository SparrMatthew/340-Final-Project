CC=gcc
CFLAGS=-c -Wall -g

all: main

main: main.o project.o
	$(CC) main.o project.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

project.o:	project.c project.h
	$(CC) $(CFLAGS) project.c

clean:
	/bin/rm -f main *.o *.gz

run:
	./main

tarball: 
	tar -cvzf sparr.tar.gz *