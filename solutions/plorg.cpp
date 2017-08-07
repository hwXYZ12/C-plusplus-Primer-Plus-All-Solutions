// plorg.cpp - ch10e7
#include "plorg.h";
#include <iostream>;

namespace PLORG
{
	
	Plorg::Plorg(const char * who) : ci(INITIAL_CI)
	{
		// copies part of the name into a C-style string
		// then ignores the rest
		for (int i = 0; i < NAME_LENGTH; i++)
		{
			name[i] = who[i];
			if (who[i] == '\0')
				break;
		}
		name[NAME_LENGTH] = '\0';
	}

	// changes the contentment index (ci) to cindex
	void Plorg::setCI(int cindex)
	{
		ci = cindex;
	}

	// reports plorg ci and name
	void Plorg::show() const
	{
		using std::cout;
		using std::endl;
		cout << "Plorg Name: " << name << endl
			 << "Contentment Index: " << ci << endl;
	}
}