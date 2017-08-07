// stack.cpp - ch10e5
#include "stack.h";

namespace STACK
{

	Stack::Stack()
	{
		top = 0;
	}

	bool Stack::isempty() const
	{
		return top == 0;
	}

	bool Stack::isfull() const
	{
		return top == MAX;
	}
	
	// push() returns false if stack already full, true otherwise
	// add item to stack
	bool Stack::push(const Item & item)
	{
		if (top < MAX)
		{
			items[top++] = item;
			return true;
		}
		else
			return false;
	}

	// pop() returns false if stack already is empty, true otherwise
	// pop top into item
	bool Stack::pop(Item & item)
	{
		if (top > 0)
		{
			item = items[--top];
			return true;
		}
		else
			return false;
	}
}