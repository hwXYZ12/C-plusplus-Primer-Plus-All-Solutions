// chapter 7 exercise 4 - ch7e4.cpp
#include <iostream>
#include <cstring>

long double probability(unsigned, unsigned);

int main()
{
	using namespace std;
	unsigned total, choices, mega;
	cout << "Enter the total number of choices on the game card, \n"
			"the number of picks allowed, \n"
			"and the total number of choices for the mega number: ";
	while((cin >> total >> choices >> mega) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices)*mega; // compute the odds
		cout << " of winning. \n";
		cout << "Next three numbers (q to quit): ";
	}
	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}

// Computes x choose y
long double probability(unsigned x, unsigned y)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for(n = x, p = y; p > 0; n--, p--)
		result = result * (n / p);

	return result;
}