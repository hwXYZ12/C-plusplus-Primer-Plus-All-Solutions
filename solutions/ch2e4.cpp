// chapter 1 exercise 4 - ch1e4.cpp
#include <iostream>
using namespace std;

int yearsToMonths(int years)
{
	return years * 12;
}

int main()
{
	cout << "Enter your age: ______\b\b\b\b\b\b";
	int age;
	cin >> age;
	cout << "\nYour age in months is: " << yearsToMonths(age) << endl;
	cin.get();
	cin.get();
	return 0;
}