// chapter 8 exercise 2 - ch8e2.cpp
#include <iostream>
#include <cstring>

// constants
const int LIMIT = 100;

// structs
struct CandyBar
{
	char * name;
	double weight;
	int calories;
};

// function used to set the members of a CandyBar struct
void setMembers(CandyBar &, char * name = "Millenium Munch", const double & weight=2.85, int calories=350);

// shows the members of a CandyBar struct
void showCandyBar(const CandyBar &);

int main()
{
	
	using namespace std;

	/* We'll run a loop to prompt the user for
	   the 3 members of the CandyBar struct
	   then set the members of a CandyBar struct,
	   display the values of the struct,
	   and start the loop again.
	*/ 

	CandyBar theGuy;
	char name[LIMIT];
	double weight;
	int calories;
	cout << "Please enter a CandyBar name (q to quit, s to skip): ";
	cin.getline(name, LIMIT);
	while(name[0]!='q'||name[1]!='\0')
	{
		if (name[0]=='s'&& name[1]=='\0')
		{
			strcpy_s(name,"Millenium Munch");
		}

		// get candybar weight
		cout << "Enter the weight of the candybar: ";
		cin >> weight;

		if (!cin)
		{
			cout << "That's not even a number! Using default value..." << endl;
			// toggle checkbit
			cin.clear();

			// set default value
			weight = 2.85;
		}

		// clear input queue
		while(cin.get() != '\n');

		// get candybar calories
		cout << "Enter the calories of the candybar: ";
		cin >> calories;

		if (!cin)
		{
			cout << "That's not even a number! Using default value..." << endl;
			// toggle checkbit
			cin.clear();

			// set default value
			calories = 350;
		}

		// clear input queue
		while(cin.get() != '\n');

		// use test functions
		setMembers(theGuy, name, weight, calories);
		showCandyBar(theGuy);

		// start the loop again
		cout << "Please enter a CandyBar name (q to quit, s to skip): ";
		cin.getline(name, LIMIT);
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// function used to set the members of a CandyBar struct
void setMembers(CandyBar & c, char * name, const double & weight, int calories)
{
	c.name = name;
	c.weight = weight;
	c.calories = calories;
}

// shows the members of a CandyBar struct
void showCandyBar(const CandyBar & c)
{
	using namespace std;
	cout << "Candybar Brand: " << c.name << endl
		 << "Weight: " << c.weight << endl
		 << "Calories: " << c.calories << endl;
}