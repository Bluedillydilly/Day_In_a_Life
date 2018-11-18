CFLAGS = -Wall -std=c99 -Wextra -pedantic
CC = gcc

triangle: triangle.o
        $(CC) $(CFLAGS) -o tri triangle.o -lncurses
triangle.o: triangle.c
        $(CC) $(CFLAGS) -c triangle.c
