#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "Entity.h"

class Room;

using namespace std;

enum itemType
{
	KEY, 
	QUEST
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* parent, itemType item_type);
	~Item();

	void Look()const;
public:
	itemType item_type;
};

#endif //_ITEM_