// chapter 2 exercise 6 - ch2e6.cpp
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of miles driven: ______\b\b\b\b\b\b ";
	double miles, gallons, mpg;
	cin >> miles;
	cout << "Enter the number of gallons used: ______\b\b\b\b\b\b ";
	cin >> gallons;
	mpg = miles / gallons;
	cout << "Your average number of miles per gallon this trip was: " << mpg << " MPG\n";
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}