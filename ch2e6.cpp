// chapter 1 exercise 6 - ch1e6.cpp
#include <iostream>
using namespace std;

double lightyearsToAstronomicalUnits(double lightyears)
{
	return lightyears * 63240;
}

int main()
{
	cout << "Enter the number of light years: ______\b\b\b\b\b\b";
	double lightyears;
	cin >> lightyears;
	cout << lightyears << " light years = " << lightyearsToAstronomicalUnits(lightyears) << " astronomical units.\n";
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}