#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"
#include "Player.h"


World::World()
{
	Room* kitchen = new Room("Kitchen", "You are in a dirty kitchen surrounded by junks\nThere is a door behind you");
	Room* livingRoom = new Room("Living Room", "You are in a huge living room\nYour mother is here\nBehing her are the stairs");
	Room* corridor = new Room("Corridor", "You have your Sister's Room on your left and Your Room on your right");
	Room* room1 = new Room("Sister's Room", "You take a huge risk going in here but okay..\nYour sister's room is plenty of things. There are documents on the table, posters on the walls and....A big diary on the floor");
	Room* room2 = new Room("Your room", "Okay man...It's time to admit your problem. It's okay having the Diogenes Syndrome.\nBy the way. Under all your junks there are the keys that you robed from your sister");
	
	Npc* mother = NULL; 

	Item* houseKey = new Item("houseKey", "Come one bro it's easy. THE KEYS FOR YOUR HOUSE", mother , QUEST);
	Item* sisterKey = new Item("key", "Your Sister's Room key. What the hell do you want me to say", room2, KEY);
	Item* diary = new Item("diary", "The diary of your beloved sister", room1, QUEST);

	mother = new Npc("mother", "Looks angry for some reason", livingRoom, sisterKey, "diary", "What the hell do you want?\nMmmm a fork? If you want one i'm not gonna buy it go get a job\nBut i'm thinking that I can help you if you help me. Go get your sister's diary and give it to me. That girl is hanging with an idiot and i want to know all the details\nIf you do that for me i will give you the keys of the house, so you can go aoutside and ask for a fork to someone else.\n");

	Exit* exit1 = new Exit("door", "An old creapy door", kitchen, livingRoom, false, NULL);
	Exit* exit2 = new Exit("stairs", "At least seven steps, I don't know how you are going to do it.", livingRoom, corridor, false, NULL);
	Exit* exit3 = new Exit("sisterDoor", "Your Sisters Room door with a sign that says DANGER", corridor, room1, true, sisterKey);
	Exit* exit4 = new Exit("yourDoor", "Your Room door", corridor, room2, false, NULL);

	
	allEntities.push_back(kitchen);
	allEntities.push_back(livingRoom);
	allEntities.push_back(corridor);
	allEntities.push_back(room1);
	allEntities.push_back(room2);

	allEntities.push_back(houseKey);
	allEntities.push_back(sisterKey);
	allEntities.push_back(diary);

	allEntities.push_back(mother);

	allEntities.push_back(exit1);
	allEntities.push_back(exit2);
	allEntities.push_back(exit3);
	allEntities.push_back(exit4);
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

		if (commands[0].compare("talk") == 0 || commands[0].compare("Talk") == 0)
		{
			player->Talk(commands);

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
