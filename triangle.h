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
 *  Title screen. Waits for player to press any button.
 */
void title_screen( int max_x, int max_y );


/*
    Changes the character. Does not refresh output
*/
void draw( char input , tile space );


/*
    Refreshes the screen by type of tile.
    
    @param new_map all the new tiles to refresh to.
    @param type the type of tile to refresh the output of.
*/
void refresh_screen( tile** new_map , int type );


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

#endif

