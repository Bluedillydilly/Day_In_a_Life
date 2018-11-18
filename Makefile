CFLAGS = -Wall -std=gnu99 -Wextra -pedantic
CC = gcc
NLIB = -lncurses
	
triangle: triangle.o
		$(CC) $(CFLAGS) -o tri triangle.o $(NLIB)
triangle.o: triangle.c
		$(CC) $(CFLAGS) -c triangle.c $(NLIB)
