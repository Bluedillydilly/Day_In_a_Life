/* triangle.c */

#include <stdlib.h> // idk yet, will probably need
#include <curses.h> // for output

#include "triangle.h" // for prototypes and typedefs

int main( int argc , char *argv[] )
{
    initscr();
    cbreak();
    noecho();
    keypad( stdscr , TRUE );
    int width = getmaxx( stdscr );

    WINDOW *win = newwin( 30 , 30 , 0 , 0 );
    
    char ch = getch();
    while( ch != 'q'  )
    {
        ch = getch();
    }
    delwin(win);
    endwin();
  
    return 0;
}
