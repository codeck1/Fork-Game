#ifndef __World__
#define __World__

#include <string>
#include <list>
#include<vector>
#include "Room.h"

using namespace std;

class Entity;

class World
{
public:

	World();
	~World();
	void commandEntries(vector<string>& commands);

public:
	Room* roomm;
private:

	list<Entity*> allEntities;
};
#endif //__World__