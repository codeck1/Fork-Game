#ifndef _CREATURE_
#define _CREATURE_

//Include
#include <string>
#include <vector>
#include <iostream>
#include "Room.h"

class Room;

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	virtual void Look(const vector<string>& args);

public:
	bool isAlive;


};

#endif //__Creature__
