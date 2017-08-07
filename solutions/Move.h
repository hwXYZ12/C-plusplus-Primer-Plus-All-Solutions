// Move.h - ch10e6
#ifndef MOVE_H_
#define MOVE_H_

namespace MOVE
{
	class Move
	{
	private:
		double x;
		double y;
	public:
		Move(double a=0, double b=0);		// sets x, y to a, b
		void showMove() const;				// shows current x, y values

		// adds x of m to x of the invoking object to get the new x
		// adds y of m to y of the invoking object to get the new y
		// creates a new Move object initialized to the the new
		// x, y values and returns it.
		Move add(const Move & m) const;

		// resets x, y to a, b
		void reset(double a=0, double b=0);
	};
}

#endif