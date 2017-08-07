// chapter 1 exercise 5 - ch1e5.cpp
#include <iostream>
using namespace std;

int celsiusToFahrenheit(int degsCelsius)
{
	return degsCelsius * 1.8 + 32;
}

int main()
{
	cout << "Please enter a Celsius value: ______\b\b\b\b\b\b";
	int cel;
	cin >> cel;
	cout << cel << " degrees in Celsius is " << celsiusToFahrenheit(cel) << " degrees Fahrenheit.\n";
	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}