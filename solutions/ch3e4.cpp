// chapter 2 exercise 4 - ch2e4.cpp
#include <iostream>
using namespace std;
const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main()
{
	cout << "Enter the number of seconds: ______\b\b\b\b\b\b ";
	long long seconds;
	cin >> seconds;
	long long  days, hours, minutes, temp = seconds;
	days = seconds / (HOURS_PER_DAY*MINUTES_PER_HOUR*SECONDS_PER_MINUTE);
	seconds = seconds % (HOURS_PER_DAY*MINUTES_PER_HOUR*SECONDS_PER_MINUTE);
	hours = seconds / (MINUTES_PER_HOUR*SECONDS_PER_MINUTE);
	seconds = seconds % (MINUTES_PER_HOUR*SECONDS_PER_MINUTE);
	minutes = seconds / SECONDS_PER_MINUTE;
	seconds = seconds % SECONDS_PER_MINUTE;
	cout << temp << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds.\n";
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}