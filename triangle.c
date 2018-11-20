/* triangle.c */
#define _XOPEN_SOURCE
#include <stdlib.h> // idk yet, will probably need
#include <ncurses.h> // for output
#include <string.h> // for dealing with and manipulating strings 
#include <unistd.h> // usleep

#include "triangle.h" // for prototypes and typedefs

#define SPELL_DELAY 15000

/*
 * Draws basic border around the screen. Consists of '+' for corners and '-'s and '|' for sides.
 * @param screen the window to draw the border
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
 *  Spells out a word to the specified window char by char.
 *  @param word the word to be displayed to the window win.
 *  @param win the window to have word displayed to.
 *  @param maxy the maximum y value of the window win.
 *  @param maxx the maximum x value of the window win.
 */
void spell_out( char* word, WINDOW* win, int maxy, int maxx)
{
    if( maxy+strlen(word) >= getmaxx(win) || maxy == 0)
    {
        fprintf( stderr, "%s\n", "String too long to print within borders at position." );
    }
    else if( maxy >=  getmaxy( win ) || maxy == 0 )
    {
        fprintf( stderr, "%s\n", "String to be printed would either print on border or out of bounds." );
    }
    for( unsigned int p = 0; p < strlen(word); p++ )
    {
        wmove( win , maxy, maxx + p );
        wdelch( win );
        winsch( win, word[p] );
        wrefresh( win );
        usleep( SPELL_DELAY );
    }
}

/*
 *  Returns x position to start printing the word out at.
 *  @param word the word to center.
 *  @param win the window that the text will be centered in.
 *  @return the x value to start printing the word at for the word to be centered.
 */
int center_text( char* word, WINDOW *win)
{
    return ( getmaxx(win) - strlen(word) ) / 2;
}

/*
 *  Centers the cursor on a provided y level in a provided window.
 *  @param win the window to center the cursor in.
 *  @param y the y level for the cursor to be centered on.
 */
void center_cursor( WINDOW *win, int y)
{
    wmove( win, y, getmaxx( win )/2 );
}

void underline_word( char* word, WINDOW* win, int maxy, int maxx )
{
    char *underline = malloc( sizeof(word) );
    strcpy( underline, word );
    for( unsigned int i = 0; i<strlen(word); i++ )
    {
        underline[i]='-';
    }
    maxy+=1;
    spell_out( underline, win, maxy, maxx );
}

/*
 * displays title of game and waits for user input
 */
void title_screen(int maxx, int maxy)
{
    WINDOW *start = newwin( maxy, maxx,  0 , 0);
    draw_borders( start );
    char* title = "This is a test Title for the unnamed game based in ncurses";
    int x_c = center_text( title, start ); 
    spell_out( title, start, maxy/5, x_c );
    underline_word( title, start, maxy/5, x_c );
    center_cursor( start, maxy/4 );
    //sleep(4);
    wgetch( start ); // holds until input
    usleep( SPELL_DELAY );
    delwin(start);
}

/*
 *
 */
int main()
{
    // initializes curses environment 
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

    //sleep(3);
    //title screen
    delwin(win);
    delwin(another_one);
    endwin();
  
    return 0;
}
