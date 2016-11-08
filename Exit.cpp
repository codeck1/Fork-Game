#include "Exit.h"


Exit::Exit(const char * name, const char * description, Room * currents, Room * destinations, bool isLocked) : Entity(name, description, (Entity*)currents)
{
	type = EXIT;
	isLocked = false;
	current = currents;
	destination = destinations;
	destination->entities.push_back(this);


}

Exit::~Exit()
{

}

void Exit::look()
{
	cout << description << "\n";
	cout << name << " to " << destination->name << "\n";


}
