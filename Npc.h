#ifndef _NPC_
#define _NPC_

#include "Creature.h"
#include "Entity.h"
#include "Item.h"

class Npc : public Creature
{
public:
	Npc(const char* name, const char* description, Room* room, Item* itemPosesion, const char* itemWanted, const char* dialog);
	void Look();
	Item* change(Item* toChange);
	
public:
	const char* wanted;
	Item* posesion;
	const char* dialogNpc;
};

#endif // _NPC_
