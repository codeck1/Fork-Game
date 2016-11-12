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
	string aux;


	cout << "Welcome to the fabulous, incredible, formidable and amazing FORK \n";
	cout << "*EXPLOSIONS EVERYWHERE*\n";
	
	while (1)
	{
		getline(cin, entry);
		istringstream iss(entry);
		
		while (iss >> aux)
			commands.push_back(aux);

		new_world.commandEntries(commands);
		commands.clear();

	}
	

	return 0;
}
