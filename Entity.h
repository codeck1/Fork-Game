#ifndef _ENTITY_
#define _ENTITY_

//Include
#include <string>
#include <list>
#include <iostream>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER,
	NPC

};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* parent);

	virtual ~Entity();

	virtual void Look() const;

	void ChangeParentTo(Entity* newParent);

public:
	EntityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> entities;



};
#endif //_ENTITY_
