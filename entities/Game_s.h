/*
    Header file for prototypes and possible typedefs.
    File name: Game_s.h
    
*/

#ifndef Game_s_h
#define Game_s_h

#include "Player_s.h"

/////////////
// STRUCTS //
/////////////


typedef struct Game_s
{
    Player_s Player; //information related to the player
};

///////////////
// FUNCTIONS //
///////////////

Game_s* createNewGame(char* playerName);

#endif