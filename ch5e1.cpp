// chapter 5 exercise 1 - ch5e1.cpp
#include <iostream>

int main()
{
	using namespace std;
	long a,b;
	cout << "Please enter 2 integers, smallest first: ";
	cin >> a;
	cout << "Second integer: ";
	cin >> b;
	// Compute the sum of integers from a to b
	long c=0;
	for (long i=a; i<=b; i++)
		c += i;
	cout << "The sum of integers from " << a << " to " << b << " is " << c << ".\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}