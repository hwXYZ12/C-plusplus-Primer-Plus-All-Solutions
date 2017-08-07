// stack2.h - ch12e4
#ifndef STACK2_H_
#define STACK2_H_

namespace STACK2
{
	template <class Item>
	class Stack
	{
	private:
		enum {MAX = 10};		// constant specific to class
		Item * pitem;			// hold stack items
		int size;				// number of items in stack
		int top;				// index for top stack item
	public:
		Stack(int n = MAX);		// creates stack with n elements
		Stack(const Stack<Item> & st);
		~Stack();
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
		bool push(const Item & item);	// add item to stack
		// pop() returns false if stack already is empty, true otherwise
		bool pop(Item & item);			// pop top into item
		Stack<Item> & operator=(const Stack<Item> & st);
	};

	// constructor, creates a stack with n elements
	template <class Item>
	Stack<Item>::Stack(int n)
	{
		// enforce max size
		if (n > MAX)
		{
			pitem = new Item[MAX];
			size = MAX;
		}
		else
		{	
			pitem = new Item[n];
			size = n;
		}
		top = 0;
	}

	// copy constructor
	template <class Item>
	Stack<Item>::Stack(const Stack<Item> & st)
	{
		// get storage for items
		pitem = new Item[st.size];
		size = st.size;

		// create a deep copy of each item in
		// the stack assuming that the copy constructor
		// for the Item class is also defined
		for(int i = 0; i < st.size; ++i)
			pitem[i] = Item(st.pitem[i]);

		top = st.top;
	}
	
	// destructor
	template <class Item>
	Stack<Item>::~Stack()
	{
		delete [] pitem;
	}
	
	// overloaded = operator
	template <class Item>
	Stack<Item> & Stack<Item>::operator=(const Stack & st)
	{
		// free memory pointed to by pitem
		delete [] pitem;

		// get storage for items
		pitem = new Item[st.size];
		size = st.size;

		// create a deep copy of each item in
		// the stack assuming that the copy constructor
		// for the Item class is also defined
		for(int i = 0; i < st.size; ++i)
			pitem[i] = Item(st.pitem[i]);

		top = st.top;
		return *this;
	}

	
	template <class Item>
	bool Stack<Item>::isempty() const
	{
		return top == 0;
	}
	
	template <class Item>
	bool Stack<Item>::isfull() const
	{
		return top == size;
	}
	
	// push() returns false if stack already full, true otherwise
	// add item to stack
	template <class Item>
	bool Stack<Item>::push(const Item & item)
	{
		if (top < size)
		{
			pitem[top++] = item;
			return true;
		}
		else
			return false;
	}

	// pop() returns false if stack already is empty, true otherwise
	// pop top into item
	template <class Item>
	bool Stack<Item>::pop(Item & item)
	{
		if (top > 0)
		{
			item = pitem[--top];
			return true;
		}
		else
			return false;
	}
}

#endif