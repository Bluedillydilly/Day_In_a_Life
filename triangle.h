/*
    Header file for prototypes and possible typedefs.

    
*/

#ifndef tri_h
#define tri_h

typedef struct tile_S{
    int row;
    int col;
    char value;
    int type;
} tile;

typedef enum tile_type{
    space,
    background,
    entity,
    objects,
}tile_type; 

/*
    Changes the character. Does not refresh output
*/
void draw( char input , tile space );

/*
    Refreshes the screen by type of tile.
    @param new_map all the new tiles to refresh to.
    @param type the type of tile to refresh the output of
*/
void refresh_screen( tile** new_map , int type );

/*
    
*/
tile *new_tile( int row , int col , char value , int type ); 

#endif

