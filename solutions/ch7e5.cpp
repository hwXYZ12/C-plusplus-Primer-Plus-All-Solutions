// chapter 7 exercise 5 - ch7e5.cpp
#include <iostream>

long double fact(long double);

int main()
{
	using namespace std;
	long double val;
	cout << "Enter a number x and we will compute x!: ";
	while((cin >> val) && val >= 0)
	{
		cout << val << "! = " << fact(val) << endl;
		cout << "Enter another positive value x and we will compute x! (q to quit): ";
	}
	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}

// Computes factorial x recursively
long double fact(long double x)
{
	if (x <= 0)
		return 1;

	return x*fact(x-1);
}