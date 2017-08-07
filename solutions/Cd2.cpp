// Cd2.cpp - ch13e2
#include "Cd2.h";
#include <iostream>;

namespace CD
{
	// constructor
	CD::CD(char * s1, char * s2, int n, double x)
	{

		int len1 = 0, len2 = 0;

		// strlen can't handle nullptr
		// note that strlen will cause undefined
		// behavior if a programmer passes a
		// non-null terminated string as an argument
		if (nullptr != s1)
			len1 = strlen(s1);
		if (nullptr != s2)
			len2 = strlen(s2);

		// using dynamic memory allocation
		performers = new char[len1 + 1];
		label = new char[len2 + 1];

		// copy given strings into CD object
		strcpy_s(performers, len1 + 1, s1);
		strcpy_s(label, len2 + 1, s2);
		selections = n;
		playtime = x;
	}

	// copy constructor
	CD::CD(const CD & d)
	{

		int len1 = 0, len2 = 0;

		// strlen can't handle nullptr
		// note that strlen will cause undefined
		// behavior if a programmer passes a
		// non-null terminated string as an argument
		if (nullptr != d.performers)
			len1 = strlen(d.performers);
		if (nullptr != d.label)
			len2 = strlen(d.label);

		// using dynamic memory allocation
		performers = new char[len1 + 1];
		label = new char[len2 + 1];
		
		// copy given strings into CD object
		strcpy_s(performers, len1 + 1, d.performers);
		strcpy_s(label, len2 + 1, d.label);
		selections = d.selections;
		playtime = d.playtime;
	}

	// default constructor
	CD::CD()
	{
		// using dynamic memory
		char * temp1 = "No performers";
		char * temp2 = "No label";

		int len1 = strlen(temp1);
		int len2 = strlen(temp2);

		performers = new char[len1 + 1];
		label = new char[len2 + 1];

		// copy default strings into CD object
		strcpy_s(performers, len1 + 1, temp1);
		strcpy_s(label, len2 + 1, temp2);
		selections = 0;
		playtime = 0.0;
	}

	// destructor
	CD::~CD()
	{
		delete [] performers;
		delete [] label;
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
		// free storage
		delete [] performers;
		delete [] label;

		int len1 = 0, len2 = 0;

		// strlen can't handle nullptr
		// note that strlen will cause undefined
		// behavior if a programmer passes a
		// non-null terminated string as an argument
		if (nullptr != d.performers)
			len1 = strlen(d.performers);
		if (nullptr != d.label)
			len2 = strlen(d.label);

		// using dynamic memory allocation
		performers = new char[len1 + 1];
		label = new char[len2 + 1];
		
		// copy data
		strcpy_s(performers, len1 + 1, d.performers);
		strcpy_s(label, len2 + 1, d.label);


		selections = d.selections;
		playtime = d.playtime;

		return *this;
	}

}
