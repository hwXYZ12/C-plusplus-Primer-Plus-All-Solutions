// Move.cpp - ch10e6
#include "Move.h";
#include <iostream>;

namespace MOVE
{
	// sets x, y to a, b
	Move::Move(double a, double b)
	{
		x = a;
		y = b;
	}

	// shows current x, y values
	void Move::showMove() const
	{
		using std::cout;
		using std::endl;
		cout << "X: " << x << endl
			 << "Y: " << y << endl;
	}

	// adds x of m to x of the invoking object to get the new x
	// adds y of m to y of the invoking object to get the new y
	// creates a new Move object initialized to the the new
	// x, y values and returns it.
	Move Move::add(const Move & m) const
	{
		return Move(x + m.x, y + m.y);
	}

	// resets x, y to a, b
	void Move::reset(double a, double b)
	{
		x = a;
		y = b;
	}

}