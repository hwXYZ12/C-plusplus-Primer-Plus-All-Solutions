// chapter 2 exercise 3 - ch2e3.cpp
#include <iostream>
using namespace std;
const double SECONDS_PER_MINUTE = 60.0;
const double MINUTES_PER_DEGREE = 60.0;

double computeDegrees(int degrees, int minutes, int seconds)
{
	return (double) degrees + minutes / MINUTES_PER_DEGREE + seconds / (MINUTES_PER_DEGREE * SECONDS_PER_MINUTE);
}

int main()
{
	cout << "Enter a latitude in degrees, minutes, and seconds (as integers).\n";
	cout << "First, enter the degrees: ______\b\b\b\b\b\b";
	int degs, mins, secs;
	cin >> degs;
	cout << "Next, enter the minutes: ______\b\b\b\b\b\b";
	cin >> mins;
	cout << "Finally, enter the seconds: ______\b\b\b\b\b\b";
	cin >> secs;
	cout << degs << " degree(s), " << mins << " minute(s), " << secs << " second(s) = " << computeDegrees(degs, mins, secs) << " degrees." << endl;
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}