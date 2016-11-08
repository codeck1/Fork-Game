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
	Exit* getExit(string arg);
	list<Exit*> exits;
};

#endif //_Room_