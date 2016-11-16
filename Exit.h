#ifndef __Exit__
#define __Exit__
//Include
#include <string>
#include <list>
#include <iostream>
#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Room;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* currents, Room* destinations, bool isLocked, Item* itemUnlock);
	~Exit();
	void Look()const;
	bool Unlock(Item* item);

	void ChangeDest();

public:
	Room* current;
	Room* destination;
	bool  locked;
	Item* unlocker;

};

#endif //__Exit__







