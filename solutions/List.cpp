// List.cpp - ch10e8
#include "List.h";

namespace LIST
{

	// adds an item to the list
	bool List::add(Item & elem)
	{
		if (!isFull())
		{
			dataStructure[index] = &elem;
			// increment index to show that an item has been
			// added to the list (note that index represents the
			// number of items in the list)
			index++;
			return true;
		}	
		return false;
	}

	// checks if the list is empty
	bool List::isEmpty() const
	{
		return index == 0;
	}

	// checks if the list is full
	bool List::isFull() const
	{
		return index == maxSize;
	}

	// visits each object in the list and performs
	// a given action on each object
	void List::visit(void (*pf)(Item &))
	{
		for( int i = 0; i < index; i++)
		{
			(*pf)(*(dataStructure[i]));
		}
	}
}