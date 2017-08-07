// stonewt.h - ch11e5 & ch11e6
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>;

namespace STONEWT
{
	class Stonewt
	{
	private:
		enum Mode { STONE_POUNDS, POUNDS }; 
		static const int LBS_PER_STN = 14;		// pounds per stone
		int stone;								// whole stones
		double pds_left;						// fractional pounds
		double pounds;							// entire weight in pounds
		Mode state;								// display mode
	public:
		// constructor for double pounds
		explicit Stonewt(double lbs, Mode m = POUNDS);

		// constructor for stone, lbs
		Stonewt(int stn, double lbs, Mode m = STONE_POUNDS);

		//default constructor
		Stonewt(Mode m = STONE_POUNDS);

		// destructor
		~Stonewt();

		// operator overloading
		Stonewt operator+(const Stonewt & t) const;
		Stonewt operator-(const Stonewt & t) const;
		Stonewt operator*(const Stonewt & t) const;

		// show weight in either stone format or pound format depending on the mode
		friend std::ostream & operator<<(std::ostream & os, const Stonewt & t);

		// change state functions (inlined)
		void toPounds() {state = POUNDS;}
		void toStonePounds() {state = STONE_POUNDS;}

		// overload relational operators (inlined)
		bool operator>(const Stonewt & t) const
			{ return pounds > t.pounds; }
		bool operator>=(const Stonewt & t) const
			{ return pounds >= t.pounds; }
		bool operator<(const Stonewt & t) const
			{ return pounds < t.pounds; }
		bool operator<=(const Stonewt & t) const
			{ return pounds <= t.pounds; }
		bool operator==(const Stonewt & t) const
			{ return pounds == t.pounds; }
		bool operator!=(const Stonewt & t) const
			{ return pounds != t.pounds; }


	};
}

#endif