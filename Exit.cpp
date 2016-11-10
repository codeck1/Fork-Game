#include "Exit.h"


Exit::Exit(const char * name, const char * description, Room * currents, Room * destinations, bool isLocked, Item * itemUnlock) : Entity(name, description, (Entity*)currents)
{
	type = EXIT;
	isLocked = false;
	current = currents;
	destination = destinations;
	destination->entities.push_back(this);
	unlocker = itemUnlock;
}

Exit::~Exit()
{

}

void Exit::Look()
{
	cout << description << "\n";
	cout << name << " to " << destination->name << "\n";

}

bool Exit::Unlock(Item * item)
{
	if (item != NULL && isLocked == true && item == unlocker)
	{
		isLocked == false;
		return true;
	}
	return false;
}

