// people.cpp - ch14e4
#include "people.h";
#include <iostream>;
#include <climits>;

namespace PEOPLE
{
	using std::cout;
	using std::cin;
	using std::endl;


	void Person::show() const
	{
		cout << "First Name: " << m_fname << endl
			 << "Last Name: " << m_lname << endl;
	}

	void GunSlinger::show() const
	{
		Person::show();
		cout << "Drawtime: " << m_drawtime << endl
			 << "Gun Notches: " << m_notches << endl;
	}

	void BadDude::show() const
	{
		GunSlinger::show();
	}

}
