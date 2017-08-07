// chapter 13 exercise 2 - ch13e2.cpp
#include <iostream>;
#include "Cd2.h";
#include "Classic2.h";

void Bravo(const CD::CD & disk);

int main()
{
	using CD::CD;
	using CLASSIC::Classic;
	using std::cout;
	CD c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Plane Sonata in B flat, Fantasia in C",
						 "Alfred Brendel", "Philipe", 2, 57.17);

	CD * pcd = &c1;

	cout << "Using Object directly:\n";
	c1.report();		// use CD method
	c2.report();		// use Classic method

	cout << "Using type cd * pointer to objects: \n";
	pcd->report();		// use CD method for cd object
	pcd = &c2;
	pcd->report();		// use Classic method for classic object

	cout << "Calling a function with a CD reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:\n";
	Classic copy;
	copy = c2;
	copy.report();

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

void Bravo(const CD::CD & disk)
{
	disk.report();
}

