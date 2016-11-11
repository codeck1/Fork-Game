#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"
#include "Player.h"


World::World()
{
	Room* kitchen = new Room("Kitchen", "You are in a dirty kitchen surrounded by junks");
	Room* livingRoom = new Room("Living Room", "You are in a huge living room");

	Exit* exit1 = new Exit("kitchen door", "An old creapy door", kitchen, livingRoom, false, NULL);

	allEntities.push_back(kitchen);
	allEntities.push_back(livingRoom);

	allEntities.push_back(exit1);
	roomm = kitchen;

	player = new Player("Elliot", "Poor pubescent", kitchen);
	allEntities.push_back(player);
}

World::~World()
{
}

void World::commandEntries(vector<string>& commands)
{

	

		if (commands[0].compare("look") == 0 || commands[0].compare("Look") == 0)
		{
			
			player->Look(commands);

		}
	
		if (commands[0].compare("go") == 0 || commands[0].compare("Go") == 0)
		{
			player->Go(commands);

		}
		
		if (commands[0].compare("use") == 0 || commands[0].compare("Use") == 0)
		{
			player->Use(commands);

		}
	
		if (commands[0].compare("inventory") == 0 || commands[0].compare("Inventory") == 0)
		{
			player->Inventory();

		}
	
		if (commands[0].compare("drop") == 0 || commands[0].compare("Drop") == 0)
		{
			player->Drop(commands);

		}

		if (commands[0].compare("pick") == 0 || commands[0].compare("Pick") == 0)
		{
			player->Pick(commands);

		}
	
}
