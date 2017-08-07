// chapter 6 exercise 2 - ch6e2.cpp
#include <iostream>
#include <cctype>
#include <array>
const int ArSize = 10;

int main()
{
	using namespace std;

	cout << "Please enter " << ArSize << " donation values or enter 'q' to terminate input.\n";
	array<double, ArSize> donations;
	int entered = 0;
	for(int i=0; i < ArSize; ++i)
	{
		cout << "Value " << i+1 << ": ";
		if (!(cin >> donations[i]))
			break;
		++entered;
	}
	if (!cin)
	{
		cin.clear();
		cin.get();
	}

	// Compute average of donations
	double avg = 0;
	for(int i=0; i < entered; ++i)
	{
		avg += donations[i];
	}
	avg = avg/ArSize;

	// Compute number above average
	int count=0;
	for(int i=0; i < entered; ++i)
	{
		if (avg < donations[i])
			++count;
	}

	cout << "\nThe average of the entered donations is " << avg;
	cout << " and the number of donations above the average donation is " << count << ".\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}