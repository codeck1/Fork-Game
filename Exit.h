#ifndef __Exit__
#define __Exit__
//Include
#include <string>
#include <list>
#include <iostream>
#include "Entity.h"
#include "Room.h"

class Room;

class Exit : public Entity
{
public:
	Exit(const char* name, const char* description, Room* currents, Room* destinations, bool isLocked, Item* item);
	~Exit();
	void Look();
	bool Unlock(Item* item);

public:
	Room* current;
	Room* destination;
	bool isLocked;

};

#endif //__Exit__







