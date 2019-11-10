/* game.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <unistd.h> // usleep
#include <curses.h>

#include "text_utils.h"

bool do_colors = 0;

/*
 *
 */
int main()
{
    // initializes curses environment 
    initscr();
    start_color();
    do_colors = has_colors();
    cbreak();
    noecho();
    keypad( stdscr , TRUE );
    
    int maxx;
    int maxy;
    getmaxyx( stdscr, maxy, maxx);
    
    // title screen
    title_screen( maxx, maxy );

    // proceed
    WINDOW *win;
    WINDOW *another_one;

    win = newwin( maxy-20, maxx, 0, 0 );
    another_one = newwin( 20, maxx, maxy-20, 0);
    draw_borders(win);
    draw_borders(another_one);
    titleWindow(win, "WIN");
    titleWindow(another_one, "another_one");
    wrefresh(win);
    wrefresh(another_one);
    
    random_text(win, another_one); 


    delwin(win);
    delwin(another_one);
    endwin();
  
    return 0;
}
