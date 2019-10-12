/*
 *  Text display helper functions. Functions that display text to an output curse window.
 *
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "triangle.h"

#define SPELL_DELAY_SEC 5
#define SPELL_DELAY SPELL_DELAY_SEC * 100000

/*
 * displays title of game and waits for user input
 */
void title_screen(int maxx, int maxy)
{
    WINDOW *start = newwin( maxy, maxx,  0 , 0);
    draw_borders( start );
    char* title = "This is a test Title for the unnamed game based in ncurses";
    int x_c = get_center_index( title, start ); 
    
    random_spell( title, start, maxy/5, x_c );
    under_spell( title, start, maxy/5, x_c );
    
    char *message = "Press any key to continue. ";
    normal_spell( message, start, maxy/2, get_center_index( message, start ) );  
    
    wgetch( start ); // holds until input
    delwin(start);
}

/*
 *
 */
void draw_borders( WINDOW *win )
{
    int sx;
    int sy;
    getmaxyx( win, sy, sx);

    //corners
    mvwprintw( win, 0, 0, "+" );
    mvwprintw( win, sy-1, 0, "+" );
    mvwprintw( win, 0, sx-1, "+" );
    mvwprintw( win, sy-1, sx-1, "+" );

    //side sides
    for( int i=0; i <= sy; i++ )
    {    
        mvwprintw( win, i, 0, "|" );
        mvwprintw( win, i, sx-1, "|" );
    }

    // top and bottom sides
    for( int i=0; i <= sx; i++ )
    {
        mvwprintw( win, 0, i, "-" );
        mvwprintw( win, sy-1, i, "-" );
    }
    wrefresh( win );
}

/*
 *
 */
void under_spell( char *word, WINDOW *win, int sy, int sx )
{
    char *underline = malloc( sizeof( word ) );
    strcpy( underline, word );
    for( unsigned int i =0; i<strlen(word); i++ )
    {
        underline[i]='-';
    }
    sy+=1;
    normal_spell( underline, win, sy, sx );
}

/*
 *
 */
int get_center_index( char *word, WINDOW *win )
{
    return ( getmaxx(win) - strlen(word) ) / 2;
}

/*
 *
 */
void center_spell( char *word, WINDOW *win, int sy )
{
    normal_spell( word, win, sy, get_center_index( word, win ) );
}

/*
 *
 */
void swap( int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 *
 */
void random_spell( char *word, WINDOW *win, int sy, int sx )
{
    if( sx + (int)strlen( word ) >= getmaxx( win ) || sx == 0 )
    {
        fprintf( stderr, "%s\n", "String too long to print within borders at provided position." );
    }
    else if( sy >=  getmaxy( win ) || sy == 0)
    {
        fprintf( stderr, "%s\n", "String would either be on border or out of bounds." );
    }
    else
    {
        int ordering[ strlen( word ) ];
        for( unsigned int i = 0; i < strlen( word ); i++ )
        {
            ordering[i] = i;
        }
        srand( time(NULL) );
        for( int i = strlen( word ) - 1 ; i > 0; i--)
        {
            int index = rand() % ( i+1 );
            swap( &ordering[i], &ordering[index] );
        }
        
        for( unsigned int p = 0; p < strlen( word ); p++ )
        {
            wmove( win, sy, sx + ordering[p] );
            wdelch( win );
            winsch( win, word[ ordering[p] ] );
            wrefresh( win );
            usleep( SPELL_DELAY );
        }
    }
}

/*
 * Display word character by character to the window.
 */ 
void char_spell( char *word, WINDOW *win, int sy, int sx )
{
    if( sx + (int)strlen( word ) >= getmaxx( win ) || sx == 0 )
    {
        fprintf( stderr, "%s\n", "String too long to print within borders at provided position." );
    }
    else if( sy >=  getmaxy( win ) || sy == 0)
    {
        fprintf( stderr, "%s\n", "String would either be on border or out of bounds." );
    }
    else
    {
        for( unsigned int p = 0; p < strlen( word ); p++ )
        {
            wmove( win, sy, sx + p );
            wdelch( win );
            winsch( win, word[p] );
            wrefresh( win );
            usleep( SPELL_DELAY );
        }
    }
}

/*
 * Displays a word to the window.
 */ 
void normal_spell( char *word, WINDOW *win, int sy, int sx )
{
    if( sx + (int)strlen( word )  >= getmaxx( win ) || sx == 0 )
    {
        fprintf( stderr, "%s\n", "String too long to print within borders at provided position." );
    }
    else if( sy >=  getmaxy( win ) || sy == 0)
    {
        fprintf( stderr, "%s\n", "String would either be on border or out of bounds." );
    }
    else
    {
        for( unsigned int p = 0; p < strlen( word ); p++ )
        {
            wmove( win, sy, sx + p );
            wdelch( win );
            winsch( win, word[p] );
        }
        wrefresh( win );
        usleep( SPELL_DELAY );
    }
}

/*
 *  Spells out a word to a window. See triangle.h for more information.
 */
void spell_out( char *word, WINDOW *win, int sy, int sx, int mode )
{
    switch(mode){
        
        case NORMAL:
            normal_spell( word, win, sy, sx);
            break;

        case CHAR:
            char_spell( word, win, sy, sx );
            break;

        case CENTER:
            center_spell( word, win, sy );
            break;

        case UNDERLINE:
            under_spell( word, win, sy, sx ); 
            break;

        case RANDOM:
            random_spell( word, win, sy, sx );
            break;

        default:
            normal_spell( word, win, sy, sx);
    }
}

/*  Centers the cursor on a provided y level in a provided window.
 *  @param win the window to center the cursor in.
 *  @param y the y level for the cursor to be centered on.
 */
void center_cursor( WINDOW *win, int y )
{
    wmove( win, y, getmaxx( win )/2);
}
