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
	for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
	{
		if (args[1].compare((*it)->name) == 0)
		{
			cout << "\nYou drop" << (*it)->name << "I hope you know what you are doing";
			(*it)->ChangeParentTo(parent);
			return true;

		}
	}
	cout << "\nBro. Whatever you are trying to drop, you don't have it.";
	return false;
	
}

bool Player::Use(const vector<string>& args)
{
	Item* item;
	
	if (args.size == 1 || args.size == 2)
	{
		cout << "\nCome on bro. Tell me what to use and where";
	}
	else 
	{
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
		{
			if (args[1].compare((*it)->name) == 0)
			{
				item = (Item*)*it;
				cout << "\nUsing" << (*it)->name;
				break;
			}
		}
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			if (args[2].compare((*it)->name) == 0 || args[3].compare((*it)->name) == 0)
			{
				if ((*it)->type == EXIT && item->item_type == KEY )
				{
					Exit* exit = (Exit*)(*it);
					if(exit->Unlock(item));
					{
						entities.remove(item);
						cout << "\nNow the " << exit->name << " is open";
					}
				}
				else
					if ((*it)->type == NPC && item->item_type == QUEST)
					{
						Npc* npc = (Npc*)(*it);
						Item* recived = npc->change(item);
						if (recived != NULL)
						{
							cout << "\nYou recived " << recived->name << " changed for " << item->name;
							recived->ChangeParentTo(this);
						}
					}

			}

		}

	}
	
	return false;
}

void Player::Inventory()
{
	if (entities.size == 0)
	{
		cout << "\nSorry buddy, but you don't have anything, but, Who really has things in this world, where everything is money and money...";
		return;
	}
	else
	{
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
		{
			cout << "\n" << (*it)->name;
		}
	}
}

bool Player::Pick(const vector<string>& args)
{
	return false;
}
