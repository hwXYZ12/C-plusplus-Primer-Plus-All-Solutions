// Wine.h - ch14e1
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

	class Wine
	{
	private:
		std::string			m_name;
		PairArray			m_pairArrayInt;
		int					m_numOfYears;
	public:

		// constructors
		// initialize members to default values
		Wine()
			: m_name(DEFAULT_NAME),
			  m_numOfYears(DEFAULT_YEARS),
			  m_pairArrayInt(ArrayInt(DEFAULT_NUM_ELEMENTS), ArrayInt(DEFAULT_NUM_ELEMENTS))
		{}
		// initialize each array to the given int arrays
		Wine(const char * l, int y, const int yr[], const int bot[])
			: m_name(l),
			  m_numOfYears(y),
			  m_pairArrayInt(ArrayInt(yr, y), ArrayInt(bot, y)) 
		{}
		// initialize empty arrays with y elements
		Wine(const char * l, int y)
			: m_name(l),
			  m_numOfYears(y),
			  m_pairArrayInt(ArrayInt(y), ArrayInt(y)) 
		{}

		// inline methods
		std::string & label()				{ return m_name; }
		int sum()							{ return m_pairArrayInt.second().sum(); }

		void getBottles();
		void show();
	};

}


#endif