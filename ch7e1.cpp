// chapter 7 exercise 1 - ch7e1.cpp
#include <iostream>

double computeHarmonicMean(double, double);

int main()
{
	using namespace std;

	cout << "Please enter pairs of numbers. To indicate you'd like to stop entering numbers, enter a pair with 0." << endl; 

	int on = 1;
	double n1, n2;
	while (on)
	{
		cout << "Please enter a pair of numbers.\n1st number: ";
		while (!(cin >> n1))
		{
			cout << "That's not a number! If you'd like to stop entering numbers, please enter 0." << endl;
			cout << "1st number: ";

			// Clear input
			while (cin.get() != '\n')
			cin.clear();
		}
		if (0 == n1)
		{
			break;
		}

		cout << "2st number: ";
		while (!(cin >> n2))
		{
			cout << "That's not a number! If you'd like to stop entering numbers, please enter 0." << endl;
			cout << "2st number: ";
			
			// Clear input
			while (cin.get() != '\n')
			cin.clear();
		}
		if (0 == n2)
		{
			break;
		}
		
		// Display harmonic mean of the pair of numbers
		cout << "The harmonic mean of the pair of numbers you've entered is: " << computeHarmonicMean(n1,n2) << endl;
	}

	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}

double inline computeHarmonicMean(double x, double y)
{
	return (2.0*x*y / (x+y));
}