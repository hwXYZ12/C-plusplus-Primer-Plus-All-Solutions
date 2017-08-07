// chapter 7 exercise 6 - ch7e6.cpp
#include <iostream>

unsigned fillArray(double[], unsigned);
void showArray(const double[], unsigned);
void reverseArray(double[], unsigned);
void swap(double[], unsigned, unsigned);
const unsigned MAX_ARRAY_SIZE = 10;

int main()
{
	using namespace std;
	
	// Fill an array
	double arr[MAX_ARRAY_SIZE];
	unsigned size = fillArray(arr, MAX_ARRAY_SIZE);
	// Show the array
	cout << "Here are the values stored in the array: ";
	showArray(arr, size);
	cout << endl;
	// Reverse the array
	reverseArray(arr, size);
	// Show the array
	cout << "The values in the array haved been reversed." << endl;
	cout << "Here they are: ";
	showArray(arr, size);
	cout << endl;

	// Reverse all but the 1st and last elements of the array...
	reverseArray(arr, size); // first reverse everything
	// now swap the 1st and last elements back to their original positions
	double temp = arr[0];
	arr[0] = arr[size-1];
	arr[size-1] = temp;

	// Show the array
	cout << "We've reversed all but the 1st and last elements of the array." << endl;
	cout << "Here's the new array: ";
	showArray(arr, size);
	cout << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// Prompts user for values to enter into an array of doubles
// The user may enter at most maxSize values, each will be placed sequentially
// into arr[] - the user may terminate this process early.
unsigned fillArray(double arr[], unsigned maxSize)
{
	using namespace std;

	// In case the user tries to fill an array of size 0
	if (maxSize <= 0)
		return 0;

	cout << "Please enter " << maxSize << " values to fill the array (q to quit)." << endl;
	int i=0;
	cout << "Value " << (i+1) << ": ";
	while(cin >> arr[i])
	{
		i++; // increase count
		if (i >= maxSize) // don't ask for any more values
			break;
		cout << "Value " << (i+1) << ": ";
	}

	// Clear any faulty input the program may have recieved
	cin.clear();
	while(cin.get() != '\n');

	// Returns the number of values entered
	return i;
}

// Shows size elements of array arr on a single line
void showArray(const double arr[], unsigned size)
{
	using namespace std;

	// Input error handling
	if (size <= 0)
		return;

	for(int i=0; i < size - 1; i++)
		cout << arr[i] << " ";
	cout << arr[size-1]; // we don't want an extra " " at the end of the output
}

// Reverses the elements in an array of doubles with size size
void reverseArray(double arr[], unsigned size)
{

	// Input error handling
	if (size <= 0)
		return;

	for(unsigned i=0, j=size-1; i < j; i++, j-- )
		swap(arr, i, j);
}

// Predicate used to swap two elements of an array of doubles
// where x and y represent the positions of the elements to be swapped
void swap(double arr[], unsigned x, unsigned y)
{
	double temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
