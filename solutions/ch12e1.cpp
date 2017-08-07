// chapter 12 exercise 1 - ch12e1.cpp
#include <iostream>;
#include "Cow.h";

int main()
{
	using COW::Cow;
	using std::cout;
	using std::cin;
	using std::endl;

	// default constructor
	Cow c1;

	// constructor
	Cow c2("Herp the Cow?", "Painting", 100.0);

	// copy constructor
	Cow c3(c1);

	// destructor is called automatically when this block
	// is left

	// assignment operator overload
	Cow c4 = c2;

	// other functionality
	c1.showCow();
	cout << endl;
	c2.showCow();
	cout << endl;
	c3.showCow();
	cout << endl;
	c4.showCow();
	cout << endl;

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}