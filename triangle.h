/*
    Header file for prototypes and possible typedefs.

    
*/

#ifndef tri_h
#define tri_h
#include <curses.h> // for WINDOW type
// structs 
//
typedef struct tile_S{
    int row;
    int col;
    char graphic;
    int type;
} tile;

typedef struct entity_S{
    tile position;
    char graphic;
} entity;


// enums
//
/*
 *  Enum of the tile types corresponding to their value.
 */
typedef enum tile_type{
    space_t,
    background_t,
    entity_t,
    objects_t,
} tile_type;

/*
 *
 */
typedef enum print_mode_e{
    NORMAL,
    CHAR,
    CENTER,
    UNDERLINE,
    RANDOM,
} print_mode;

/*
 *  Title screen. Waits for player to press any button.
 */
void title_screen( int max_x, int max_y );


/*
    Changes the character. Does not refresh output
*/
void draw( char input , tile space );

/*
    Creates a new tile for the map.

    @param row the row the new tile will be located at.
    @param col the col the new tile will be located at.
    @param graphic the visual representation of the tile when outputted.
    @param type the tile type, see enum tile_type for more info.
    
    @return a pointer to the new tile. Will return NULL pointer will tile at that location already exists.
    
    @post new tile is first at that position. It is not returning a pointer to a tile that occupies the same location as another.
*/
tile *new_tile( int row , int col , char graphic , int type ); 


// FUNCTIONS RELATED TO OUTPUTTING TEXT TO A CURSE WINDOW

/*
 *
 *  MODES:
 *      0 - normal mode. Prints at line maxy, starting at the maxx character in the win window. Refreshes at the end
 *      1 - character by character mode. Prints normally, by refreshs whenever a character is inserted.
 *      2 - center mode. Prints at line maxy, starting at x value that outputs the text in the center of the window win.
 *      3 - underline mode. Prints normally, however, for each character in word, there will be a '-' printed below it.
 *      4 - random mode. Prints characters out of order.
 *
 */ 
void spell_out( char *word, WINDOW *win, int maxy, int maxx, int mode );

void normal_spell( char *word, WINDOW *win, int maxy, int maxx );

void char_spell( char *word, WINDOW *win, int maxy, int maxx );

void center_spell( char *word, WINDOW *win, int maxy);

void under_spell( char *word, WINDOW *win, int maxy, int maxx );

void random_spell( char *word, WINDOW *win, int maxy, int maxx );

/*
 *
 */ 
int get_center_index( char *word, WINDOW *win);

/*
 *
 */ 
void center_cursor( WINDOW *win, int y );


#endif

