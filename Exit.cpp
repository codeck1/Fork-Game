#include "Exit.h"


Exit::Exit(const char * name, const char * description, Room * currents, Room * destinations, bool isLocked, Item * itemUnlock) : Entity(name, description, (Entity*)currents)
{
	type = EXIT;
	locked = isLocked;
	current = currents;
	destination = destinations;
	destination->entities.push_back(this);
	unlocker = itemUnlock;
}

Exit::~Exit()
{

}

void Exit::Look()const
{
	cout << description << "\n";
	cout << name << " to " << destination->name << "\n";

}

bool Exit::Unlock(Item * item)
{
	if (item != NULL && locked == true && item == unlocker)
	{
		locked = false;
		return true;
	}
	return false;
}
void Exit::ChangeDest()
{
	Room* aux = current;
	current = destination;
	destination = aux;
}

