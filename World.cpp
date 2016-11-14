#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"
#include "Player.h"


World::World()
{
	Room* kitchen = new Room("Kitchen", "You are in a dirty kitchen surrounded by junks.\nThere is some sugar splited on the floor.\nThere is a door behind you");
	Room* livingRoom = new Room("Living Room", "You are in a huge living room\nYour mother is here\nBehing her are the stairs");
	Room* corridor = new Room("Corridor", "You have your Sister's Room on your left and Your Room on your right");
	Room* room1 = new Room("Sister's Room", "You take a huge risk going in here but okay..\nYour sister's room is plenty of things. There are documents on the table, posters on the walls and....A big diary on the floor");
	Room* room2 = new Room("Your room", "Okay man...It's time to admit your problem. It's okay having the Diogenes Syndrome.\nBy the way. Under all your junks there are the keys that you robed from your sister");
	Room* street1 = new Room("Street", "The street in front of your house. How much time has passed, since you went out the last time?\nThere is a huge machine. Maybe to fix the road");
	Room* street2 = new Room("Closed road", "Oh man. The street is closed, there is a big hole in the middle...Oh shit don't go...\nOh shit\n...\nElliot?\n....Elliot?\n I can't belive you're such an idiot. Oh my god, now you are dead and i have no one to guide. Thanks Elliot. Very kind.");
	Room* street3 = new Room("Street of Mrs Lylypad", "The house of Mrs Lylypad is in front of you. And that little granny is at the door.");
	Room* nhouse = new Room("Mrs Lylypad House", "You go in and...There is...The fork.\n THE MOTHERFUCKING PRECIOUS FORK\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOH\nNice Elliot. Your meaningless life is now worth.");

	Item* houseKey = new Item("housekey", "Come one bro it's easy. THE KEYS FOR YOUR HOUSE", nhouse, KEY);
	Item* lKey = new Item("lylypadkey", "The keys from Mrs Lylypad", nhouse, KEY);
	Item* screw = new Item("screw", "The proof that you broke the machine", nhouse, QUEST);

	Npc* mother = mother = new Npc("mother", "Looks angry for some reason", livingRoom, houseKey, "diary", "What the hell do you want?\nMmmm a fork? If you want one i'm not gonna buy it go get a job\nBut i'm thinking that I can help you if you help me. Go get your sister's diary and give it to me. That girl is hanging with an idiot and i want to know all the details\nIf you do that for me i will give you the keys of the house, so you can go aoutside and ask for a fork to someone else.\n");
	Npc* Lylypad = Lylypad = new Npc("lylypad", "An old little granny", street3, lKey, "screw", "Hello sweaty.\nA fork? Yes i have one inside, but if you want to go in first you have to make me a favor. You hear that shity machine at the end of the street?\nWell...I belive in your thug skills to make something ;).");
	Npc* machine = machine = new Npc("machine", "A big noisy machine", street1, screw, "sugar", "Looks like it has a hole. Maybe you can put something inside");
	
	houseKey->ChangeParentTo(mother);
	lKey->ChangeParentTo(Lylypad);
	screw->ChangeParentTo(machine);
	Item* sisterKey = new Item("key", "Your Sister's Room key. What the hell do you want me to say", room2, KEY);
	Item* diary = new Item("diary", "The diary of your beloved sister", room1, QUEST);
	Item* sugar = new Item("sugar", "Man...The sugar...For your coffe o whatever you drink for your breakfast...I don't know...breastmilk? Kiddo",kitchen, QUEST);
	

	
	Exit* exit1 = new Exit("door", "An old creapy door", kitchen, livingRoom, false, NULL);
	Exit* exit2 = new Exit("stairs", "At least seven steps, I don't know how you are going to do it.", livingRoom, corridor, false, NULL);
	Exit* exit3 = new Exit("housedoor", "Your house door. Big and beauty.", livingRoom, street1, true, houseKey);
	Exit* exit4 = new Exit("sisterdoor", "Your Sisters Room door with a sign that says DANGER", corridor, room1, true, sisterKey);
	Exit* exit5 = new Exit("yourdoor", "Your Room door", corridor, room2, false, NULL);
	Exit* exit6 = new Exit("left", "The road for the other street", street1, street2, false, NULL);
	Exit* exit7 = new Exit("right", "The road for the other street", street1, street3, false, NULL);
	Exit* exit8 = new Exit("lylypaddoor", "The Lylypad's house door", street3, nhouse, true, lKey);

	
	allEntities.push_back(kitchen);
	allEntities.push_back(livingRoom);
	allEntities.push_back(corridor);
	allEntities.push_back(room1);
	allEntities.push_back(room2);
	allEntities.push_back(street1);
	allEntities.push_back(street2);
	allEntities.push_back(street3);
	allEntities.push_back(nhouse);

	allEntities.push_back(houseKey);
	allEntities.push_back(sisterKey);
	allEntities.push_back(diary);
	allEntities.push_back(sugar);
	allEntities.push_back(lKey);
	allEntities.push_back(screw);

	allEntities.push_back(mother);
	allEntities.push_back(Lylypad);
	allEntities.push_back(machine);

	allEntities.push_back(exit1);
	allEntities.push_back(exit2);
	allEntities.push_back(exit3);
	allEntities.push_back(exit4);
	allEntities.push_back(exit5);
	allEntities.push_back(exit6);
	allEntities.push_back(exit7);
	allEntities.push_back(exit8);
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
