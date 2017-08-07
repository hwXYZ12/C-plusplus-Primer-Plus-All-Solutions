// Person.cpp - ch10e2
#include "Person.h";
#include <iostream>;

namespace PERSON
{

	Person::Person(const string & ln, const char * fn) : lname(ln) 
	{
		// copy part of the given string and ignore the rest
		for(int i = 0; i < LIMIT; i++)
		{
			fname[i] = fn[i];
		}
		fname[LIMIT-1] = '\0';
	}

	// firstname lastname format
	void Person::Show() const
	{
		using std::cout;
		using std::endl;

		cout << fname << " " << lname;
	}

	// lastname, firstname format
	void Person::FormalShow() const
	{
		using std::cout;
		using std::endl;

		cout << lname << ", " << fname;
	}
}