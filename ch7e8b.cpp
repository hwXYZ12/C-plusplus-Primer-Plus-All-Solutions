// chapter 7 exercise 8b - ch7e8b.cpp
#include <iostream>

// constant data
const int SEASONS = 4;
const char* SEASON_NAMES[SEASONS] = {"Spring", "Summer", "Fall", "Winter"};

// struct representing seasonal expenses
struct expenses
{
	double values[SEASONS];
};

// function to modify array object
void fill(expenses*);
// function that uses the array object without modifying it
void show(expenses);

int main()
{
	using namespace std;
	expenses theGuy;
	fill(&theGuy);
	show(theGuy);
	// clear input queue
	while(cin.get() != '\n');
	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// fills an array with values that are meant to represent
// expenses incurred each quarter of the year
// this function has no error detection.....
void fill(expenses* costs)
{
	using namespace std;
	for(int i=0; i < SEASONS; i++)
	{
		cout << "Enter " << SEASON_NAMES[i] << " expenses: ";
		cin >> costs->values[i];
	}
}

// shows the values in the given array
void show(expenses costs)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i=0; i < SEASONS; i++)
	{
		cout << SEASON_NAMES[i] << ": $" << costs.values[i] << endl;
		total += costs.values[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
