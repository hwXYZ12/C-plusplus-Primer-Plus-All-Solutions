// chapter 7 exercise 7 - ch7e7.cpp
#include <iostream>

double* fillArray(double[], unsigned);
void showArray(const double*, const double*);
void revalue(double, double*, double*);
const unsigned MAX = 10;

int main()
{
	using namespace std;
	
	// Fill an array of doubles
	double arr[MAX];
	double* end = fillArray(arr, MAX);
	showArray(&arr[0], end);
	cout << endl;

	if (&arr[0] != end)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while(!(cin >> factor)) // bad input
		{
			cin.clear();
			while(cin.get() != '\n');
			cout << "Bad input; Please enter a number: ";
		}

		// clear input queue
		while(cin.get() != '\n');
		revalue(factor, &arr[0], end);
		showArray(&arr[0], end);
		cout << endl;
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// Prompts user for values to enter into an array of doubles
// The user may enter at most maxSize values, each will be placed sequentially
// into arr[] - the user may terminate this process early.
// the returned double* pointer points to a location d1irectly after the last
// input value
double* fillArray(double arr[], unsigned maxSize)
{
	using namespace std;
	double temp;
	unsigned i;
	for(i=0; i < maxSize; i++)
	{
		cout << "Enter value #" << (i+1) << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Bad input; input process terminated. \n";
			break;
		} 
		else if (temp < 0) // signal to terminate
		{
			// clear input queue
			while(cin.get() != '\n');
			break;
		}
		arr[i] = temp;
	}

	// returns a location directly after the last element of input
	// where &arr[i] is the address directly after the address of the last element of input
	return &arr[i];
}

// Shows all double elements from the start address to the
// end address, excluding the element found at the end address
void showArray(const double* start, const double* end)
{
	using namespace std;

	// Input error handling
	if (start >= end)
		return;
	
	while(start < (end-1))
	{
		cout << *start << " ";
		start++;
	}
	cout << *(end-1); // we don't want to print an extra " "
}

// Multiplies all the double values in a range by a revaluation factor
void revalue(double val, double* start, double* end)
{
	while(start < end)
	{
		*start *= val;
		start++;
	}
}
