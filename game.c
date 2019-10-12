/* triangle.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <string.h> // for dealing with and manipulating strings 
#include <unistd.h> // usleep
#include <curses.h>

#include "triangle.h"

bool do_colors = 0;

/*
 *
 */
void random_text(WINDOW* win1, WINDOW* win2)
{
    WINDOW *current_window = win1;
    char input;
    
    while( input != 'q' )
    {
        input = wgetch(current_window);
        current_window = input%2 == 1 ? win1 : win2 ;
        wdelch(current_window);
        winsch(current_window, input);
        wmove(current_window, rand()%getmaxy(current_window) , rand()%getmaxx(current_window));
    }

}

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
    mvwprintw(win, 1, 1, "WIN");
    mvwprintw(another_one, 1, 1, "another_one");
    wrefresh(win);
    wrefresh(another_one);
    
    random_text(win, another_one); 


    delwin(win);
    delwin(another_one);
    endwin();
  
    return 0;
}
