// Wine2.h - ch14e2
#ifndef WINE_H_
#define WINE_H_
#include <string>;
#include "Pair.h";
#include <valarray>;

namespace WINE
{
	typedef std::valarray<int> ArrayInt;
	typedef PAIR::Pair< ArrayInt, ArrayInt > PairArray;

	// class constants
	static const char * DEFAULT_NAME = "None";
	static const int DEFAULT_YEARS = 0;
	static const int DEFAULT_NUM_ELEMENTS = 0;

	class Wine : private std::string, PairArray
	{
	private:
		int					m_numOfYears;
	public:

		// constructors
		// initialize members to default values
		Wine()
			: std::string(DEFAULT_NAME),
			  m_numOfYears(DEFAULT_YEARS),
			  PairArray(ArrayInt(DEFAULT_NUM_ELEMENTS), ArrayInt(DEFAULT_NUM_ELEMENTS))
		{}
		// initialize each array to the given int arrays
		Wine(const char * l, int y, const int yr[], const int bot[])
			: std::string(l),
			  m_numOfYears(y),
			  PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) 
		{}
		// initialize empty arrays with y elements
		Wine(const char * l, int y)
			: std::string(l),
			  m_numOfYears(y),
			  PairArray(ArrayInt(y), ArrayInt(y)) 
		{}

		// inline methods
		std::string & label()				{ return (std::string &) *this; }
		int sum()							{ return ((PairArray &) *this).second().sum(); }

		void getBottles();
		void show();
	};

}


#endif