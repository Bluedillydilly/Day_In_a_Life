/*
	File Name: Owner.c
*/

#include "Owner.h"
#include "Location_s.h"

Owner_s* createNewOwner(const char* newName, Location_s* loc)
{
	Owner_s* newOwner_s;

	// allocate new space for Owner_s pointer
	newOwner_s = (Owner_s*) calloc( 1, sizeof(Owner_s));

	// check if space allocation successful
	if( newOwner_s != NULL )
	{
		newOwner_s->name = newName;
		newOwner_s->location = loc;
		newOwner_s->num_stores = 0;
	}
}

int addStore(Owner_s* owner, Store_s* new_store)
{
	(owner->owned_stores)[owner->num_stores] = new_store;
	owner->num_stores += 1;
}

int storeCount(Owner_s* owner)
{
	return owner->num_stores;
}

char* portfolio()
{
	return "WIP";
}