#include "Exit.h"


Exit::Exit(const char * name, const char * description, Room * currents, Room * destinations) : Entity(name, description, (Entity*)currents)
{
	type = EXIT;

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
