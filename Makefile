CC=gcc
FLAGS=-Wextra -Wall -std=gnu99 -ggdb
LIBS=-lncurses


game: game.o text_utils.o
	$(CC) $(FLAGS) -o game game.o text_utils.o $(LIBS)

game.o: game.c triangle.h
	$(CC) -c $(FLAGS) game.c

text_utils.o: text_utils.c triangle.h
	$(CC) -c $(FLAGS) text_utils.c
