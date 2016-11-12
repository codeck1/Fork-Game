#include "Exit.h"
#include "Room.h"

Room::Room(const char * name, const char * description) : Entity(name, description, NULL)
{
	type = ROOM;
	
}

Room::~Room()
{
}

void Room::Look()
{
	cout << name << "\n";
	cout << description << "\n";

	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
	{
		
		if ((*it)->type == EXIT)
		{

			Exit* exit = (Exit*)*it;
			Room* room = exit->destination;
			Room* room2 = exit->current;
			cout <<"\n" << exit->name << "\n Direcction to: " << (room)->name << " from " << (room2)->name;
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

