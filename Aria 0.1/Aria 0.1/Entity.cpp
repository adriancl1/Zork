#include "Entity.h"

Entity::Entity(const char* name, const char* description, type mytype) : name(name), description(description), my_type(mytype)
{

}

char* Entity::get_name()const
{
	return name.c_str();
}

char* Entity::get_description()const
{
	return description.c_str();
}

void Entity::Look()const
{
	printf("%s\n%s", name.c_str(), description.c_str());
}


void Entity::Insert(Entity* container)
{

}

void Entity::Remove(Entity* container){}
/*void Entity::Insert(Entity* container)
{
	if (this->my_type == ITEM){
		if ((container->my_type == ROOM || container->my_type == PLAYER) && container->my_entities.size < 8 && this->container != container)//You can only store items in room or the player inventory, and the max number of items you can hold at once is 8.
		{
			this->container = container;
			container->my_entities.push_back(this);
			printf("%s is now inside %s", this->get_name, container->get_name);
		}
		else{
			printf("You can't store that in there!\n");
		}
	}
	else{
		printf("You can't store something that's not an item!\n");
	}
}

void Entity::Remove(Entity* container)
{
	if (this->my_type == ITEM){
		if ((container->my_type == PLAYER)&& this->container == container)//You can only remove items from the player inventory.
		{
			this->container=container->
			container->my_entities.push_back(this);
			printf("%s is now inside %s", this->get_name, container->get_name);
		}
		else{
			printf("You can't remove that from there!\n");
		}
	}
	else{
		printf("You can't remove something that's not an item!\n");
	}
}*/