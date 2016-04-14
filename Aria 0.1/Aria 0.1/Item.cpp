#include "Item.h"

Item::Item(const char* name, const char* description, Entity* container) : Entity(name, description, ITEM), container(container)
{

}

Item::~Item(){}

void Item::Insert(Entity* container)
{
	if (this->my_type == ITEM){
		if ((container->my_type == ROOM || container->my_type == PLAYER) && container->my_entities.size() < 8 && this->container != container)//You can only store items in room or the player inventory, and the max number of items you can hold at once is 8.
		{
			this->container = container;
			container->my_entities.push_back(this);
			printf("%s is now inside %s", this->get_name(), container->get_name());
		}
		else{
			printf("You can't store that in there!\n");
		}
	}
	else{
		printf("You can't store something that's not an item!\n");
	}
}

void Item::Remove(Entity* container)
{
	if (this->my_type == ITEM){
		if ((container->my_type == PLAYER) && this->container == container)//You can only remove items from the player inventory.
		{
			container->my_entities.Remove(this);
			this->container = container;
			container->my_entities.push_back(this);
			printf("%s is now out of %s", this->get_name(), container->get_name());
		}
		else{
			printf("You can't remove that from there!\n");
		}
	}
	else{
		printf("You can't remove something that's not an item!\n");
	}
}