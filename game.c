/* game.c */
#define _DEFAULT_SOURCE // silence 'usleep impilict declaration' warning
#include <stdlib.h> // idk yet, will probably need
#include <unistd.h> // usleep
#include <ncurses.h>

#include "game.h"


/**
 * configures Ncurses - colors, keypad, echo'ing, etc.
 */
void init_env(char** argv)
{
    // initializes curses environment 
    initscr();

    // COLOR CHECK
    if (has_colors() == FALSE) // color not supported
    {
        endwin();
        printf("TERMINAL DOESN'T SUPPORT COLOR\n");
        exit(-1);
    }
    start_color(); // color supported
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    attron(A_UNDERLINE);
    printw("This is a test!");
    refresh();

    attron(COLOR_PAIR(2));
    printw("This is a test!");
    refresh();

    getch();

    cbreak();
    noecho();
    keypad(stdscr, TRUE);    
}



/**
 * 
 * Returns:
 *      0: arguments are valid
 *      1: invalid arguments
 */
int arg_check(int argc, char** argv)
{
    printf("Args (%d):\n", argc);
    for (int i = 1; i < argc; i++) { // skip './game' arg
        printf("\t%d: '%s'\n", i, argv[i]);
        // check for color mode
        // check for save file
    }
    return 0;
}



/**
 * 
 */
void usage_print()
{
    char* usage_string = "Usage: sPOOP";
    fprintf(stdout, "%s\n", usage_string);

    return;
}



/*
 *
 */
int main(int argc, char** argv)
{
    if( arg_check(argc, argv) )
    {
        usage_print();
        exit(-1);
    }
    // arg_check(argc, argv);
    init_env(argv);

    int maxx;
    int maxy;
    getmaxyx(stdscr, maxy, maxx);

    // window declaration
    WINDOW* win;
    WINDOW* another_one;

    // window initialization
    win = newwin(maxy-20, maxx, 0, 0);
    another_one = newwin(20, maxx, maxy-20, 0);

    borders_easy(win);
    borders_easy(another_one);

    title_screen(win);

    random_text_WEIRD(win, another_one);
    clear_redraw(another_one, win);
    title_screen(another_one);
    delwin(win);
    delwin(another_one);
    endwin();

    return 0;
}