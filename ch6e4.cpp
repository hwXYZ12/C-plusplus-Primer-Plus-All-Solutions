// chapter 6 exercise 4 - ch6e4.cpp
#include <iostream>
#include <cctype>
#include <string>
const int NUM_EMPLOYEES = 3;

int main()
{
	using namespace std;


	struct bop
	{
		string fullname;	// real name
		string title;		// job title
		string bopname;		// secret BOP name
		int preference;		// 0 = fullname, 1 = title, 2 = bopname
	};

	bop emps[NUM_EMPLOYEES] =
	{
		{ "Mike Jones", "CEO", "The Myth", 0},
		{ "Herb Jones", "Senior Programmer", "The Legend", 2},
		{ "Rick Ross", "Tester", "ComeAtMeBro", 1}
	};

	cout << "Please enter one of the following choices: \n";
	cout << "a. display by name			b. display by title\n";
	cout << "c. display by BOP name			d. display by preference\n";
	cout << "q. quit";
	cout << "\nPlease enter a choice: ";

	char ch;
	bool quit = false;
	while (cin >> ch)
	{
		switch (ch)
		{
			case 'a':
			case 'A': for(int i=0; i < NUM_EMPLOYEES; ++i)
					  {
						  cout << emps[i].fullname << endl;
					  }
					  break;
			case 'b':
			case 'B': for(int i=0; i < NUM_EMPLOYEES; ++i)
					  {
						  cout << emps[i].title << endl;
					  }
					  break;
			case 'c':
			case 'C': for(int i=0; i < NUM_EMPLOYEES; ++i)
					  {
						  cout << emps[i].bopname << endl;
					  }
					  break;
			case 'd':
			case 'D': for(int i=0; i < NUM_EMPLOYEES; ++i)
					  {
						  switch (emps[i].preference)
						  {
								case 0: cout << emps[i].fullname << endl;
										break;
								case 1: cout << emps[i].title << endl;
										break;
								case 2: cout << emps[i].bopname << endl;
										break;
						  }
						  
					  }
					  break;
			case 'q':
			case 'Q': cout << "You've chosen to quit the program.";
					  quit = true;
					  break;
			default: ;
		}
		if (!quit)
			cout << "Please enter a choice: ";
		else
			break;
	}
	
	cout << "\nPress ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}