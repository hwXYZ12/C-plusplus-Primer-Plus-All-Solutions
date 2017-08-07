// chapter 2 exercise 7 - ch2e7.cpp
#include <iostream>
using namespace std;
const long double MILES_PER_100KM = 62.14L;
const long double LITERS_PER_GALLON = 3.875L;

long double computeUsMpg(long double euMpg)
{
	return MILES_PER_100KM * LITERS_PER_GALLON / euMpg;
}

int main()
{
	cout << "Enter your gasoline consumption figure European style;\n that is in terms of liters per 100 kilometers: ______\b\b\b\b\b\b ";
	long double euMpg;
	cin >> euMpg;
	if (euMpg == 0)
	{
		cout << "BAD INPUT - Please enter a nonzero number.\n";
	} else 
	{
		cout << "Your US gasoline consumption figure is: " << computeUsMpg(euMpg) << " MPG\n";
	}
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}