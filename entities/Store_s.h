/*
    Header file for prototypes and possible typedefs.
    File name: Store_s.h
    
*/

#ifndef Store_s_h
#define Store_s_h

#include "Owner.h"

/////////////
// STRUCTS //
/////////////

typedef struct Store_s
{
	char* name; //Name of the store
	Location_s location; //Info about where the store is
	Owner_e owner_type; //What type of owner controls the store
	Owner_s owner; //Who the owner of the store is
};

#endif