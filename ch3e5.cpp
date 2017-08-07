// chapter 2 exercise 5 - ch2e5.cpp
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the world population: ______\b\b\b\b\b\b ";
	long long worldPop, usPop;
	long double f;
	cin >> worldPop;
	cout << "Enter the population of the US: ______\b\b\b\b\b\b ";
	cin >> usPop;
	f = usPop / (long double) worldPop * 100.0;
	cout << "The population of the US is " << f << "% of the world population.\n";
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}