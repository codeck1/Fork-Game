#include "Npc.h"

Npc::Npc(const char * name, const char * description, Room * room, Item * itemPosesion, const char * itemWanted, const char * dialog) : Creature(name, description, room)
{
	type = NPC;
	wanted = itemWanted;
	posesion = itemPosesion;
	dialogNpc = dialog;
}

void Npc::Look()
{
	cout << name;
	cout << description << "\n";
}

Item * Npc::change(Item * toChange)
{
	if (toChange->name == wanted)
	{
		Item* itemToChange = posesion;
		return itemToChange;
	}
	else
	{
		return nullptr;
	}
}
