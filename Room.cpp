#include "Exit.h"
#include "Room.h"

Room::Room(const char * name, const char * description, roomType typeRoom) : Entity(name, description, NULL)
{
	type = ROOM;
	typeR = typeRoom;
}

Room::~Room()
{
}

void Room::Look()const
{
	cout << "\n" << name <<  "\n";
	cout << description << "\n";

	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
	{
		if (typeR == END )
		{
			return;
		}
		if ((*it)->type == EXIT)
		{

			Exit* exit = (Exit*)*it;
			Room* room = exit->destination;
			Room* room2 = exit->current;
			cout <<"\n" << exit->name << "\n Direcction to: " << (room)->name << " from " << (room2)->name << "\n";
		}
	}

}

Exit * Room::getExit(string arg)
{
	{
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
		{
			if ((*it)->type == EXIT && (*it)->name == arg)
			{
				Exit* exit = (Exit*)*it;
				return exit;

			}
		}
		return NULL;

	}
}

roomType Room::roomEnd()
{
	return typeR;
}


