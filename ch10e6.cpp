// chapter 10 exercise 6 - ch10e6.cpp
#include <iostream>;
#include "Move.h";

int main()
{

	using std::cout;
	using std::cin;
	using std::endl;
	using MOVE::Move;

	// create a Move object
	Move p = Move(10, 10);

	// show current position
	cout << "Our current location." << endl;
	p.showMove();
	cout << endl;

	// create and show another position
	Move q = Move(-5, 30);
	cout << "Second position vector generated." << endl;
	q.showMove();
	cout << endl;

	// show sum of positions
	cout << "Our new position calculated by adding the two vectors." << endl;
	Move & t = p.add(q);
	t.showMove();
	cout << endl;

	// reset position
	cout << "We've reset our position to (0, 0)." << endl;
	t.reset();
	t.showMove();
	cout << endl;


	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}