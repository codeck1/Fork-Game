#ifndef _Room_
#define _Room_
//Include
#include <string>
#include <list>
#include <iostream>
#include "Entity.h"

class Exit;
class Creature;

class Room : public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();
	void look();
	void getExit();

};

#endif //_Room_