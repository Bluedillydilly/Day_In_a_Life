CC=gcc
FLAGS=-Wextra -Wall -std=gnu99 -ggdb
LIBS=-lncurses
DRAWER=display


game: game.o text_utils.o windows.o
	$(CC) $(FLAGS) -o game game.o text_utils.o windows.o $(LIBS)

game.o: game.c display/text_utils.h
	$(CC) -c $(FLAGS) game.c

text_utils.o: display/text_utils.c display/text_utils.h
	$(CC) -c $(FLAGS) $(DRAWER)/text_utils.c

windows.o: display/windows.c display/windows.h
	$(CC) -c $(FLAGS) $(DRAWER)/windows.c

clean: 
	rm *.o game
