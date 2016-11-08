#include "Player.h"

Player::Player(const char * name, const char * description, Room * room) : Creature(name, description, room)
{
	type = PLAYER;
}

Player::~Player()
{
}

void Player::Go(const vector<string>& args)
{
	Room* room = (Room*)parent;
	Exit* currentExit = room->getExit(args[1]);
	if (currentExit->isLocked)
	{
		cout << "The path is closed. If i have to tell you, you are srewed \n";
	}
	else
	{
		cout << "Goint to " << currentExit->destination->name <<"\n";
		ChangeParentTo(currentExit->destination);

	}

	
}

void Player::Look(const vector<string>& args)
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			if (args[1].compare((*it)->name) == 0)
			{
				(*it)->Look();

			}
		}
		if (args[1].compare("me") == 0)
		{
			cout << name << "\n";
			cout << description << "\n";
		}
	}
	else
	{
		parent->Look();
	}
	
}


bool Player::Drop(const vector<string>& args)
{
	return false;
}

void Player::Inventory()
{
}

bool Player::Pick(const vector<string>& args)
{
	return false;
}
