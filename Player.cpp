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
	Exit* currentExit = NULL;
	if (args.size() > 1)
	{
		if (room->getExit(args[1]) != NULL)
		{
			currentExit = room->getExit(args[1]);
			if (currentExit->locked)
			{
				cout << "The path is closed. If i have to tell you, you are srewed \n";
				return;
			}
			else
			{
				
				
				cout << "Going to " << currentExit->destination->name << "\n";
				ChangeParentTo(currentExit->destination);
				currentExit->destination->Look();
				currentExit->ChangeDest();
				
				return;

			}
		}
	}
	else
	{
		cout << "\nTell where to go\n";
		return;
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
		for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
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
		Room* room = (Room*)(parent);
		room->Look();
	}
	
}


bool Player::Drop(const vector<string>& args)
{
	for (list<Entity*>::const_iterator it = entities.begin(); it != entities.cend(); ++it)
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
	Item* item = NULL;
	
	if (args.size() <= 2)
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
				cout << "\nUsing" << (*it)->name << "\n";
				break;
			}
		}
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			if (args.size() == 3)
			{
				if (args[2].compare((*it)->name) == 0 )
				{
					if ((*it)->type == EXIT && item->item_type == KEY)
					{
						Exit* exit = (Exit*)(*it);
						if (exit->Unlock(item))
						{
							entities.remove(item);
							cout << "\nNow the " << exit->name << " is open\n";
							return true;
						}
					}
					else
						if ((*it)->type == NPC && item->item_type == QUEST)
						{
							Npc* npc = (Npc*)(*it);
							Item* recived = npc->change(item);
							if (recived != NULL)
							{
								cout << "\nYou recived " << recived->name << " changed for " << item->name << "\n";
								recived->ChangeParentTo(this);
								item->ChangeParentTo(npc);
								return true;
							}
						}
				}
			}
			else
				if (args.size() > 3)
				{
					if (args[3].compare((*it)->name) == 0)
					{
						if ((*it)->type == EXIT && item->item_type == KEY)
						{
							Exit* exit = (Exit*)(*it);
							if (exit->Unlock(item))
							{
								entities.remove(item);
								cout << "\nNow the " << exit->name << " is open\n";
								return true;
							}
						}
						else
							if ((*it)->type == NPC && item->item_type == QUEST)
							{
								Npc* npc = (Npc*)(*it);
								Item* recived = npc->change(item);
								if (recived != NULL)
								{
									cout << "\nYou recived " << recived->name << " changed for " << item->name << "\n";
									recived->ChangeParentTo(this);
									item->ChangeParentTo(npc);
									return true;
								}
							}
					}
				}
			

		}

	}
	
	return false;
}

void Player::Talk(const vector<string>& args)
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			if (args[1].compare((*it)->name) == 0 || args[2].compare((*it)->name) == 0)
			{
				Npc* npc = (Npc*)(*it);
				cout << "\n" << npc->name << " says:\n " << npc->dialogNpc;
				return;

			}
		}
	}
	else
	{
		cout << "\nTell who do you want to talk...\n";
		return;
	}
	
}

void Player::Inventory()
{
	if (entities.size() == 0)
	{
		cout << "\nSorry buddy, but you don't have anything, but, Who really has things in this world, where everything is money and money...\n";
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

void Player::Pick(const vector<string>& args)
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = parent->entities.begin(); it != parent->entities.cend(); ++it)
		{
			if ((args[1].compare((*it)->name) == 0))
			{
				cout << "\nYou take the " << (*it)->name << "\n";
				Item* picked = (Item*)(*it);
				picked->ChangeParentTo(this);
				return;
			}
		}
	}
		
}
