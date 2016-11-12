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
	cout << "You are about to eat you delicious spaguettis but.....You lost the fork. Now what??\n";
	
	while (1)
	{
		getline(cin, entry);
		istringstream iss(entry);
		while (iss >> aux)
			commands.push_back(aux);
		system("cls");
		new_world.commandEntries(commands);
		commands.clear();

	}
	

	return 0;
}
