// chapter 1 exercise 7 - ch1e7.cpp
#include <iostream>
using namespace std;

void showTime(int hours, int mins)
{
	cout << "Time: " << hours << ":" << mins << endl;
}

int main()
{
	cout << "Enter the number of hours: ______\b\b\b\b\b\b";
	int hours, mins;
	cin >> hours;
	cout << "Enter the number of minutes: ______\b\b\b\b\b\b";
	cin >> mins;
	showTime(hours, mins);
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}