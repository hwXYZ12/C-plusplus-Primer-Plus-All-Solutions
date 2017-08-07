// Classic.cpp - ch13e1
#include "Cd.h";
#include "Classic.h";
#include <iostream>;

namespace CLASSIC
{
	// constructor
	Classic::Classic(char * s1, char * s2, char * s3, int n, double x)
		: CD(s2, s3, n, x)
	{
		// lazy copy
		strcpy_s(primary, 50, s1);
	}

	// derived class constructor
	Classic::Classic(char * s1, const CD & cd)
		: CD(cd)
	{
		// lazy copy
		strcpy_s(primary, 50, s1);
	}

	// copy constructor
	Classic::Classic(const Classic & c)
		: CD(c)
	{
		// lazy copy
		strcpy_s(primary, 50, c.primary);
	}

	// default constructor
	Classic::Classic()
		: CD()
	{
		// lazy copy
		strcpy_s(primary, 50, "No primary piece");
	}

	// destructor
	Classic::~Classic()
	{

	}

	// overloaded '=' operator
	Classic & Classic::operator=(const Classic & c)
	{
		// lazy copy
		strcpy_s(primary, 50, c.primary);

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