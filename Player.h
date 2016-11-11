#ifndef _PLAYER_
#define _PLAYER_

//Include
#include "Creature.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Go(const vector<string>& args);
	void Look(const vector<string>& args);
	bool Drop(const vector<string>& args);
	bool Use(const vector<string>& args);
	void Talk(const vector<string>& args);
	void Inventory();
	void Pick(const vector<string>& args);
};

#endif //_PLAYER_
