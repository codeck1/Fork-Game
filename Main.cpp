#include <iostream>
#include <string>
#include <vector>
#include "World.h"

using namespace std;

int main()
{
	World new_world;
	vector<string> commands;
	string a;

	cout << "Welcome to FORK \n";
	commands.push_back("look");
	new_world.commandEntries(commands);
	cin >> a;
	return 0;
}
