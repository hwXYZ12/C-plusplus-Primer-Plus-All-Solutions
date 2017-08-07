// chapter 7 exercise 8a - ch7e8a.cpp
#include <iostream>

// constant data
const int SEASONS = 4;
const char* SEASON_NAMES[SEASONS] = {"Spring", "Summer", "Fall", "Winter"};

// function to modify array object
void fill(double[]);
// function that uses the array object without modifying it
void show(const double[]);

int main()
{
	using namespace std;
	double expenses[SEASONS];
	fill(expenses);
	show(expenses);
	// clear input queue
	while(cin.get() != '\n');
	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// fills an array with values that are meant to represent
// expenses incurred each quarter of the year
// this function has no error detection.....
void fill(double arr[])
{
	using namespace std;
	for(int i=0; i < SEASONS; i++)
	{
		cout << "Enter " << SEASON_NAMES[i] << " expenses: ";
		cin >> arr[i];
	}
}

// shows the values in the given array
void show(const double arr[])
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for(int i=0; i < SEASONS; i++)
	{
		cout << SEASON_NAMES[i] << ": $" << arr[i] << endl;
		total += arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
