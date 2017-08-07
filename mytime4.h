// mytime4.h - ch11e4
#ifndef MYTIME4_H_
#define MYTIME4_H_
#include <iostream>;

namespace TIME
{
	class Time
	{
	private:
		int hours;
		int minutes;
	public:
		Time();
		Time(int h, int m=0);
		void AddMin(int m);
		void AddHr(int h);
		void Reset(int h=0, int m = 0);
		// operator overloads being implemented using friend functions instead
		friend Time operator+(const Time & t1, const Time & t2);
		friend Time operator-(const Time & t1, const Time & t2);
		friend Time operator*(const Time & t, double n);
		friend Time operator*(double m, const Time & t)
		{ return t * m; }		// inline definition
		friend std::ostream & operator<<(std::ostream & os, const Time & t);
	};
}

#endif