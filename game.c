/* game.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <unistd.h> // usleep
#include <curses.h>

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
    init_pair(1, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    


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
    return 0;
}



/**
 * 
 */
void usage_print()
{
    printf("POOP");

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
    arg_check(argc, argv);
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