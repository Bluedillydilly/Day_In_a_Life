/* triangle.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <string.h> // for dealing with and manipulating strings 
#include <unistd.h> // usleep
#include <ncurses.h>

#include "triangle.h"

#define SPELL_DELAY 12500

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
    mvwprintw(win, 1, 1, "WIN");
    mvwprintw(another_one, 1, 1, "another_one");
    wrefresh(win);
    wrefresh(another_one);
    
    WINDOW *current_window = win;
    char input;
    
    while( input != 'q' )
    {
        input = wgetch(current_window);
        current_window = input%2 == 1 ? win : another_one ;
        wdelch(current_window);
        winsch(current_window, input);
        wmove(current_window, rand()%getmaxy(current_window) , rand()%getmaxx(current_window));
    }

    delwin(win);
    delwin(another_one);
    endwin();
  
    return 0;
}

/*
 * displays title of game and waits for user input
 */
void title_screen(int maxx, int maxy)
{
    WINDOW *start = newwin( maxy, maxx,  0 , 0);
    draw_borders( start );
    char* title = "This is a test Title for the unnamed game based in ncurses";
    int x_c = get_center_index( title, start ); 
    
    char_spell( title, start, maxy/5, x_c );
    under_spell( title, start, maxy/5, x_c );
    
    char *message = "Press any key to continue. ";
    normal_spell( message, start, maxy/2, get_center_index( message, start ) );  
    
    wgetch( start ); // holds until input
    usleep( SPELL_DELAY );
    delwin(start);
}

