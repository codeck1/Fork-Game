#ifndef _PLAYER_
#define _PLAYER_

//Include
#include "Creature.h"

using namespace std;

class Player : public Creature
{
public:
	Player(const char* name, const char* description, Room* room);
	~Player();

	void Go(const vector<string>& args);
	void Look(const vector<string>& args);
	bool Drop(const vector<string>& args);
	void Inventory();
	bool Pick(const vector<string>& args);
};

#endif //_PLAYER_
