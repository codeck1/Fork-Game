#include "Item.h"

Item::Item(const char * name, const char * description, Entity * parent, itemType item_type) : Entity(name, description, parent),item_type(item_type)
{
	type = ITEM;

}

Item::~Item()
{
}

void Item::Look()
{
	cout << name << "\n";
	cout << description << "\n";



}
