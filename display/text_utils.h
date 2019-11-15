/*
    Header file for prototypes and possible typedefs.
    File name: text_utils.h
    
*/

#ifndef text_h
#define text_h
#include <ncurses.h> // for WINDOW type

/////////////
// STRUCTS //
/////////////
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

///////////
// ENUMS //
///////////
/*
 *  Enum of the tile types corresponding to their value.
 */
typedef enum tile_type_E{
    space_t,
    background_t,
    entity_t,
    objects_t,
} tile_type;

/*
 * 
 */
typedef enum print_mode_E{
    NORMAL,
    CHAR,
    CENTER,
    UNDERLINE,
    RANDOM,
} print_mode;

////////////////////////////////////////////////////////////
// INTERACTIVE FUNCTIONS THAT REQUIRE USER INPUT ///////////
// IE INTERACTIVE FUNCS ////////////////////////////////////
////////////////////////////////////////////////////////////

/*
 *   Alternates random text between two windows depending on ascii value of char entered. 
 */
void random_text_WEIRD(WINDOW* win1, WINDOW* win2);

//////////////////////////////
// END OF INTERACTIVE FUNCS //
//////////////////////////////

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
tile* new_tile( int row , int col , char graphic , int type ); 


////////////////////////////////////////////////////////////
// FUNCTIONS RELATED TO OUTPUTTING TEXT TO A CURSE WINDOW //
// IE SPELLING FUNCTIONS ///////////////////////////////////
////////////////////////////////////////////////////////////

/*  
 *   MODES:
 *      0 - normal mode. Prints at line maxy, starting at the maxx character in the win window. Refreshes at the end
 *      1 - character by character mode. Prints normally, by refreshs whenever a character is inserted.
 *      2 - center mode. Prints at line maxy, starting at x value that outputs the text in the center of the window win.
 *      3 - underline mode. Prints normally, however, for each character in word, there will be a '-' printed below it.
 *      4 - random mode. Prints characters out of order.
 */ 
void spell_out( char* word, WINDOW* win, int maxy, int maxx, int mode );

/*  Spells out a starting at maxy,maxx. Spells out word.
 */
void normal_spell( char* word, WINDOW* win, int maxy, int maxx );

/*
 * 
 */
void char_spell( char* word, WINDOW* win, int maxy, int maxx );

/*
 * 
 */
void center_spell( char* word, WINDOW* win, int maxy);

/*
 * 
 */
void under_spell( char* word, WINDOW* win, int maxy, int maxx );

/*
 * 
 */
void random_spell( char* word, WINDOW* win, int maxy, int maxx );


///////////////////////////////
// END OF SPELLING FUNCTIONS //
///////////////////////////////

///////////////////////////////
// SPELLING HELPER FUNCTIONS //
///////////////////////////////

/*
 *  Gets the index to print out so word would look centered if displayed out.
 */ 
int get_center_index( char* word, WINDOW* win);

/*
 *   Moves the cursor to the middle of a given y.
 */ 
void center_cursor( WINDOW* win, int y );


#endif

