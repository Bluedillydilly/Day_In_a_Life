/*
    Header file for prototypes and possible typedefs.
    File name: Owner.h
    
*/

#ifndef Owner_h
#define Owner_h

//personal includes
#include "Location_s.h"
#include "Store_s.h"

/////////////
// TYPEDEFS //
/////////////

typedef struct Owner_s
{
	const char* name; //Name of the owner
	Location_s* location; //Where the owner is located
	Store_s** owned_stores; //Stores the owner possesses
	int num_stores; //Number of stores owned
}Owner_s;

typedef enum Owner_e
{
	Local, Corporate, Coop,
}Owner_e;

///////////////
// FUNCTIONS //
///////////////

// char representation of the assets owned by the Owner_s
char* portfolio();

// creates a new owner struct
Owner_s* createNewOwner(const char* name, Location_s* loc);

// Add a new store that the owner now controls
int addStore(Owner_s* owner, Store_s* new_store);

// Gets the number of stores the owner controls
int storeCount(Owner_s* owner);


#endif