CC=gcc
FLAGS=-Wextra -Wall -std=gnu99 -ggdb -lm
LIBS=-lncurses
WINDOWS=display
TEXT_UTILS=display/text_utilities


game: game.o text_utils.o windowDrawing.o
	$(CC) $(FLAGS) -o game game.o text_utils.o windowDrawing.o $(LIBS)

game.o: game.c $(TEXT_UTILS)/text_utils.h
	$(CC) -c $(FLAGS) game.c

text_utils.o: $(TEXT_UTILS)/text_utils.c $(TEXT_UTILS)/text_utils.h
	$(CC) -c $(FLAGS) $(TEXT_UTILS)/text_utils.c

windowDrawing.o: $(WINDOWS)/windowDrawing.c $(WINDOWS)/windowDrawing.h
	$(CC) -c $(FLAGS) $(WINDOWS)/windowDrawing.c

clean: 
	rm *.o game
