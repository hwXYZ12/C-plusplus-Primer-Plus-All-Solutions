// stonewt.cpp - ch11e5 & ch11e6
#include <iostream>;
using std::cout;
#include "stonewt.h";


namespace STONEWT
{

	// construct Stonewt object from double value
	Stonewt::Stonewt(double lbs, Mode m) : state(m)
	{
		stone = int (lbs) / LBS_PER_STN; // integer division
		pds_left = int (lbs) % LBS_PER_STN + lbs - int(lbs);
		pounds = lbs;
	}

	// construct Stonewt object from stone, double values
	Stonewt::Stonewt(int stn, double lbs, Mode m) : state(m)
	{
		stone = stn;
		pds_left = lbs;
		pounds = stn * LBS_PER_STN + lbs;
	}

	// default constructor, wt = 0
	Stonewt::Stonewt(Mode m) : state(m)
	{
		stone = pounds = pds_left = 0;
	}

	// destructor
	Stonewt::~Stonewt()
	{
		
	}

	// operator overloading
	Stonewt Stonewt::operator+(const Stonewt & t) const
	{
		return Stonewt(pounds + t.pounds);
	}

	Stonewt Stonewt::operator-(const Stonewt & t) const
	{
		return Stonewt(pounds - t.pounds);
	}

	Stonewt Stonewt::operator*(const Stonewt & t) const
	{
		return Stonewt(pounds * t.pounds);
	}

	// show weight in either stone format or pound format depending on the mode
	std::ostream & operator<<(std::ostream & os, const Stonewt & t)
	{
		if (Stonewt::POUNDS == t.state)
		{
			cout << "Pounds: " << t.pounds;
		}
		else if (Stonewt::STONE_POUNDS == t.state)
		{
			cout << "Stone, Pounds: " << t.stone << ", " << t.pds_left;
		}
		else
		{
			cout << "ERROR - Mode invalid.";
		}
		return os;
	}
}
