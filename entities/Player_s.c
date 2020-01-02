/*
	File name: Player_s.h  
*/

#include "Player_s.h" // Player_s
#include "Owner.h"

Player_s* createNewPlayer(const char* playerName, Location_s* loc)
{
	Player_s* newPlayer_s;

	// allocate new space for the Player_s pointer
	newPlayer_s = (Player_s*) calloc( 1, sizeof(Player_s));

	//check to see if the space was successfully allocated
	if( newPlayer_s != NULL )
	{
		newPlayer_s -> owner = createNewOwner(playerName, loc);
	}

	return newPlayer_s; 
}
