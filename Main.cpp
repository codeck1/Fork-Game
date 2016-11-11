#include <iostream>
#include <string>
#include <vector>
#include "World.h"
#include <sstream>


using namespace std;

int main()
{
	World new_world;
	vector<string> commands;
	string entry;

	cout << "Welcome to the fabulous, incredible, formidable and amazing FORK \n";
	cout << "*EXPLOSIONS EVERYWHERE*\n";
	
	while (1)
	{
		commands.clear();
		getline(cin, entry);
		
		commands.push_back(entry);
		new_world.commandEntries(commands);
	}
	

	return 0;
}
