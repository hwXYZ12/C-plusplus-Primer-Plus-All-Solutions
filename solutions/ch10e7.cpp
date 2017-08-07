// chapter 10 exercise 7 - ch10e7.cpp
#include <iostream>;
#include "plorg.h";

int main()
{

	using std::cout;
	using std::cin;
	using std::endl;
	using PLORG::Plorg;

	// create 2 Plorg objects
	Plorg p1 = Plorg(), p2 = Plorg("Herp the Plorg");

	// show plorgs
	cout << "We've generated 2 Plorgs to hangout with." << endl << endl;
	p1.show();
	cout << endl;
	p2.show();
	cout << endl << endl;

	cout << "Our 1st Plorg has shot itself in the foot..." << endl
		 << "The state of our Plorgs is as follows." << endl << endl;

	p1.setCI(-5000); // hardcoded
	p1.show();
	cout << endl;
	p2.show();
	cout << endl;


	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}