// Vector2.h - ch11e2 & ch11e3
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>;

namespace VECTOR
{
	class Vector
	{
	public:

		// RECT for rectangular, POL for Polar modes
		enum Mode {RECT, POL};

	private:
		double x;			// horizontal value
		double y;			// vertical value
		//double mag;			// length of vector
		//double ang;			// direction of vector in degrees
		Mode mode;			// RECT or POL

		// private methods for setting values
		//void set_mag();
		//void set_ang();

		// automatically generate polar magnitude and angle
		double getMag() const;
		double getAng() const;

		// used to set x and y coordinates given polar coordinates
		void set_x(double mag, double ang);
		void set_y(double mag, double ang);

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const {return x;}				// report x value
		double yval() const {return y;}				// report y value
		double magval() const {return getMag();}			// report magnitude
		double angval() const {return getAng();}			// report angle
		void polar_mode();							// set mode to POL
		void rect_mode();							// set mode to RECT
		void reset(double n1, double n2, Mode form = RECT); // resets the values of the vector object

		// operator overloading
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		// friends
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);

	};
}


#endif