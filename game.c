/* game.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <unistd.h> // usleep
#include <curses.h>

#include "display/text_utils.h"
#include "display/windows.h"

bool do_colors = 0;

/*
 *
 */
int main(int argc, char** argv)
{
    // initializes curses environment 
    initscr();
    start_color();
    // for colors
    do_colors = has_colors();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
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
