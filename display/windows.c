/* windows.c */

// INCLUDES
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// PERSONAL HEADERS
#include "windows.h"
#include "text_utils.h"

// MACROS
// NOT PROPERLY IMPLEMENTED
// FIND UNICODE VALUES NOT ASCII
// DEFAULT BORDERS
/* 
// DEFINES CORNER BRACKETS
#define URC "\u191"
#define ULC "\u218"
#define LLC "\u192"
#define LRC "\u217"
#define VSC "\u179"
#define HSC "\u196"
*/


/*
 *
 */
void title_window(WINDOW *win, const char *title)
{
    mvwprintw(win, 1, 1, title);
}

/*
 * displays title of game and waits for user input
 */
void title_screen(WINDOW *win )
{
    borders_easy( win );
    int maxy = getmaxy(win);
    char *title = "This is a test Title for the unnamed game based in ncurses";
    int x_c = get_center_index( title, win ); 
    
    random_spell( title, win, maxy/5, x_c );
    under_spell( title, win, maxy/5, x_c );
    
    char *message = "Press any key to continue.";
    normal_spell( message, win, maxy/2, get_center_index( message, win ) );  
    
    wgetch( win ); // holds until input
    clear_win_c( win );
}

/*
 *
 */
void borders(WINDOW *win, const char vsc, const char hsc, const char cc )
{
    wborder( win, vsc, vsc, hsc, hsc, cc, cc, cc, cc );
    wrefresh( win );
    wmove( win, 1, 1 );
}

/*
 * 
 */
void borders_easy(WINDOW *win)
{
    borders( win, '|', '-', '+' );
}

/*
 *
 */
void clear_win(WINDOW *win)
{
    wclear(win);
    wrefresh(win);
}

/*
 *
 */
void clear_win_c(WINDOW *win)
{
    clear_win(win);
    borders_easy(win);
}

/*
 * 
 */
void clear_redraw(WINDOW *btm, WINDOW *top)
{
    clear_win(top);
    clear_win_c(btm);
}
