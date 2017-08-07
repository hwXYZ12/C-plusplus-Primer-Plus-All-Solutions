// chapter 10 exercise 7 - ch10e7.cpp
#include <iostream>;
#include "List.h";

	
// test function
void incrementAndPrint(Item & thing)
{
	using std::cout;
	using std::endl;
	thing.x++;
	cout << "The value of this thing is: " << thing.x << endl;
}

int main()
{

	using std::cout;
	using std::cin;
	using std::endl;
	using LIST::List;

	// initialize some stuff
	it stuff[15];
	for(int i=0; i < 5; i++)
	{
		stuff[i].x = 20;
	}
	for(int i=5; i < 10; i++)
	{
		stuff[i].x = -20;
	}
	for(int i=10; i < 15; i++)
	{
		stuff[i].x = 0;
	}

	// let user know that stuff has been created
	cout << "Objects with these initial values have been created..." << endl;
	for (int i=0; i < 15; i++)
	{
		cout << "Value of Object " << (i+1) << ": " << stuff[i].x << endl;
	}

	// create an empty List
	List l = List(15);

	// check if list is empty
	if (l.isEmpty())
		cout << "Empty list created." << endl;

	// fill the list
	for(int i=0; i < 15; i++)
	{
		l.add(stuff[i]);
		cout << "Object Added." << endl;
	}

	// check if list is full
	if (l.isFull())
		cout << "List is now full of stuff." << endl;

	// perform action on each element of the list
	cout << "Now performing an operation on each object." << endl;
	l.visit(incrementAndPrint);

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}