#include "World.h"
#include "Room.h"
#include "Exit.h"

World::World()
{
	Room* kitchen = new Room("Kitchen", "You are in a dirty kitchen surrounded by junks");
	Room* livingRoom = new Room("Living Room", "You are in a huge living room");

	Exit* exit1 = new Exit("kitchen door", "An old creapy door", kitchen, livingRoom);

	allEntities.push_back(kitchen);
	allEntities.push_back(livingRoom);

	allEntities.push_back(exit1);
	roomm = kitchen;

}

World::~World()
{
}

void World::commandEntries(vector<string>& commands)
{

	switch (commands.size())
	{
	case 1:

		if (commands[0].compare("look") == 0)
		{
			cout << "yep";
			roomm->look();

		}
		break;

	}
}
