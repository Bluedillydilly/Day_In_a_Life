/* triangle.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <ncurses.h> // for output
#include <string.h> // for dealing with and manipulating strings 
#include <unistd.h>

#include "triangle.h" // for prototypes and typedefs

/*
 *
 */
void draw_borders(WINDOW *screen) 
{ 
    int x, y, i; getmaxyx(screen, y, x); 
    // 4 corners 
    mvwprintw(screen, 0, 0, "+"); 
    mvwprintw(screen, y - 1, 0, "+"); 
    mvwprintw(screen, 0, x - 1, "+"); 
    mvwprintw(screen, y - 1, x - 1, "+"); 
    // sides 
    for (i = 1; i < (y - 1); i++) 
    { 
        mvwprintw(screen, i, 0, "|"); 
        mvwprintw(screen, i, x - 1, "|"); 
    } // top and bottom 
    for (i = 1; i < (x - 1); i++) 
    { 
        mvwprintw(screen, 0, i, "-"); 
        mvwprintw(screen, y - 1, i, "-"); 
    }
    wrefresh(screen);
}

/*
 *
 */
void title_screen(int maxx, int maxy)
{
    WINDOW *start = newwin( maxy, maxx,  0 , 0);
    draw_borders( start );
    char* title = "This is a test Title for the unnamed game based in ncurses";
    for( unsigned int position = 0; position < strlen(title); position++ )
    {
        wmove( start, maxy/5, maxx/5 + position );
        wdelch( start );
        winsch( start, title[position] );
        wrefresh(start);
        usleep( 15000 );
    }
    sleep(4);
    //getch(); // holds until input
    delwin(start);
}

/*
 *
 */
int main()
{
    initscr();
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
    
    wmove( another_one, 1, 1);
    wdelch(another_one);
    winsch(another_one, 'X');
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

    sleep(3);
    //title screen
    delwin(win);
    delwin(another_one);
    endwin();
  
    return 0;
}
