/*
    Header file for prototypes and possible typedefs.
    File name: Player_s.h
    
*/

#ifndef Player_s_h
#define Player_s_h

#include "Owner.h"

/////////////
// STRUCTS //
/////////////

typedef struct Player_s
{
    Owner_s* owner; //Information about the player
}Player_s;

///////////////
// FUNCTIONS //
///////////////

Player_s* createNewPlayer();

#endif