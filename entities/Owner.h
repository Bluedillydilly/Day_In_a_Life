/*
    Header file for prototypes and possible typedefs.
    File name: Owner.h
    
*/

#ifndef Owner_h
#define Owner_h

#include "Location_s.h"

/////////////
// STRUCTS //
/////////////

typedef struct Owner_s
{
	char* name; //Name of the owner
	Location_s* location; //Where the owner is located
	Store_s** owned_stores; //Stores the owner possesses
	int num_stores;
};

typedef enum Owner_e
{
	Local, Corporate, Coop,
};

#endif