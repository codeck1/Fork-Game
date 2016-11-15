#ifndef _Room_
#define _Room_
//Include
#include <string>
#include <list>
#include <iostream>
#include "Entity.h"


class Exit;
class Creature;
enum roomType
{
	NORMAL,
	END
};


class Room : public Entity
{
public:
	Room(const char* name, const char* description, roomType typeRoom);
	~Room();
	void Look();
	Exit* getExit(string arg);
	list<Exit*> exits;
	roomType typeR;
	roomType roomEnd();
	
};

#endif //_Room_