// chapter 2 exercise 1 - ch2e1.cpp
#include <iostream>
using namespace std;
const int INCHES_PER_FOOT = 12;

void showHeight(int feet, int inches)
{
	cout << "You are " << feet << " feet and " << inches << " inches tall." << endl;
}

int main()
{
	cout << "Enter your height in inches (as an integer): ______\b\b\b\b\b\b";
	int height;
	cin >> height;
	int feet = height / INCHES_PER_FOOT;
	int inches = height % INCHES_PER_FOOT;
	showHeight(feet, inches);
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}