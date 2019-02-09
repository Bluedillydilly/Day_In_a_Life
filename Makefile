CC=gcc
FLAGS= -Wextra -Wall -std=gnu99 -ggdb -lncurses

game: game.o text_utils.o
	$(CC) $(FLAGS) -o game game.o text_utils.o

game.o: game.c triangle.h
	$(CC) -c $(FLAGS) game.c

text_utils.o: text_utils.c triangle.h
	$(CC) -c $(FLAGS) text_utils.c
