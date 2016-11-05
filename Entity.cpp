#include "Entity.h"

Entity::Entity(const char * name, const char * description, Entity * parent) : name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
	{
		parent->entities.push_back(this);
	}

}

Entity::~Entity()
{

}

void Entity::Look() const
{
	cout << name << "\n";
	cout << description << "\n";


}

void Entity::ChangeParentTo(Entity * newParent)
{
	if (newParent != NULL)
	{
		parent->entities.remove(this);
		newParent->entities.push_back(this);
	}



}
