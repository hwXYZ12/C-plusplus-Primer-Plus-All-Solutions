// Classic2.cpp - ch13e2
#include "Cd2.h";
#include "Classic2.h";
#include <iostream>;

namespace CLASSIC
{
	// constructor
	Classic::Classic(char * s1, char * s2, char * s3, int n, double x)
		: CD(s2, s3, n, x)
	{
		int len = 0;

		// strlen can't handle nullptr
		// and strlen will cause undefined
		// behavior if you try to pass a
		// non null terminated string
		if (nullptr != s1)
			len = strlen(s1);

		// allocate storage
		primary = new char[len + 1];

		// copy to storage
		strcpy_s(primary, len + 1, s1);
	}

	// derived class constructor
	Classic::Classic(char * s1, const CD & cd)
		: CD(cd)
	{
		
		int len = 0;

		// strlen can't handle nullptr
		// and strlen will cause undefined
		// behavior if you try to pass a
		// non null terminated string
		if (nullptr != s1)
			len = strlen(s1);

		// allocate storage
		primary = new char[len + 1];

		// copy to storage
		strcpy_s(primary, len + 1, s1);
	}

	// copy constructor
	Classic::Classic(const Classic & c)
		: CD(c)
	{
		
		int len = 0;

		// strlen can't handle nullptr
		// and strlen will cause undefined
		// behavior if you try to pass a
		// non null terminated string
		if (nullptr != c.primary)
			len = strlen(c.primary);

		// allocate storage
		primary = new char[len + 1];

		// copy to storage
		strcpy_s(primary, len + 1, c.primary);
	}

	// default constructor
	Classic::Classic()
		: CD()
	{
		char * temp = "No primary piece";
		
		int len = strlen(temp);

		// allocate storage
		primary = new char[len + 1];

		// copy to storage
		strcpy_s(primary, len + 1, temp);
	}

	// destructor
	Classic::~Classic()
	{
		delete [] primary;
	}

	// overloaded '=' operator
	Classic & Classic::operator=(const Classic & c)
	{
		// free storage
		delete [] primary;
		
		int len = 0;

		// strlen can't handle nullptr
		// and strlen will cause undefined
		// behavior if you try to pass a
		// non null terminated string
		if (nullptr != c.primary)
			len = strlen(c.primary);

		// allocate storage
		primary = new char[len + 1];

		// copy to storage
		strcpy_s(primary, len + 1, c.primary);

		// call opertator=() using base class members
		// of *this and c
		CD::operator=(c);

		return *this;
	}

	// reports all CD Data & reports the primary classical work
	void Classic::report() const 
	{
		using std::cout;
		using std::endl;
		CD::report();
		cout << "Primary Work: " << primary << endl;

	}


}