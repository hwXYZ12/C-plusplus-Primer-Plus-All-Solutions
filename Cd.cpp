// Cd.cpp - ch13e1
#include "Cd.h";
#include <iostream>;

namespace CD
{
	// constructor
	CD::CD(char * s1, char * s2, int n, double x)
	{
		// lazy copy given strings into CD object
		strcpy_s(performers, 50, s1);
		strcpy_s(label, 20, s2);
		selections = n;
		playtime = x;
	}

	// copy constructor
	CD::CD(const CD & d)
	{
		// lazy copy
		strcpy_s(performers, 50, d.performers);
		strcpy_s(label, 20, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}

	// default constructor
	CD::CD()
	{
		// default lazy copy
		strcpy_s(performers, 14, "No performers");
		strcpy_s(label, 9, "No label");
		selections = 0;
		playtime = 0.0;
	}

	// destructor
	CD::~CD()
	{

	}

	// reports all CD data
	void CD::report() const
	{
		using std::cout;
		using std::endl;
		cout << "Peformers: " << performers << endl
			 << "Label: " << label << endl
			 << "Selections: " << selections << endl
			 << "Playtime: " << playtime << endl;
	}

	// overloaded '=' operator
	CD & CD::operator=(const CD & d)
	{
		
		// lazy copy
		strcpy_s(performers, 50, d.performers);
		strcpy_s(label, 20, d.label);
		selections = d.selections;
		playtime = d.playtime;

		return *this;
	}

}
