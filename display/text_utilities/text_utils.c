/*
 *  Text display helper functions. Functions that display text to an output curse window.
 *
 */
#define _XOPEN_SOURCE
// INCLUDES
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// PERSONAL HEADERS
#include "text_utils.h"

// MACROS
#define SPELL_DELAY_SEC 1
#define SPELL_DELAY SPELL_DELAY_SEC * 10000

/*
 *
 */
void random_text_WEIRD( WINDOW *win1, WINDOW *win2 )
{
    WINDOW *current_window = win1;
    char input = wgetch(current_window);
    
    while( input != 'q' )
    {
        current_window = input%2 ? win1 : win2 ;
        wdelch(current_window);
        winsch(current_window, input);
        wmove(current_window, rand()%(getmaxy(current_window)-2) + 1 ,
                              rand()%(getmaxx(current_window)-2) + 1 );
        input = wgetch(current_window);
    }

}

/*
 *
 */
void under_spell( char *word, WINDOW *win, int sy, int sx )
{
    char *underline = malloc( sizeof( word ) );
    strcpy( underline, word );
    for( unsigned int i = 0; i < strlen(word); i++ )
    {
        underline[i] = '-';
    }
    sy += 1;
    normal_spell( underline, win, sy, sx );
    free( underline );
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
void random_spell( char *word,WINDOW *win, int sy, int sx )
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
        // PRINT MODES 
        // SEE text_utils.h:print_mode_e
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
            break;
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
