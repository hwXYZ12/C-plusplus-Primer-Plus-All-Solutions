// List.h - ch10e8
#ifndef LIST_H_
#define LIST_H_


struct it
{
	int x;
};

typedef it Item;

namespace LIST
{
	static const int MAX_SIZE = 100;
	static const int DEFAULT_SIZE = 10;

	// Will be implemented using an array of pointers
	// to Item objects
	class List
	{
	private:
		int maxSize;
		int index;
		Item * dataStructure[MAX_SIZE];

	public:

		// Creates a list of a given size
		List(int size=DEFAULT_SIZE) : maxSize(size), index(0) {};

		// adds an item to the list
		bool add(Item &);

		// checks if the list is empty
		bool isEmpty() const;

		// checks if the list is full
		bool isFull() const;

		// visits each object in the list and performs
		// a given action on each object
		void visit(void (*pf)(Item &));

	};
}

#endif