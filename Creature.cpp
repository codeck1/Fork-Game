#include "Creature.h"

Creature::Creature(const char * name, const char * description, Room * room) : Entity(name, description, (Entity*)room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}

void Creature::Look(const vector<string>& args)const
{
	if (isAlive)
	{
		cout << name << "\n";
		cout << description << "\n";
	}
	else
	{
		cout << name << "\n";
		cout << description << "Completely dead. No doubt about that.";

	}
}


