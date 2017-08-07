// chapter 8 exercise 6 - ch8e6.cpp
#include <iostream>;

// Takes an arry of items of type T as well as the size of the array 
// and returns the largest item in the array
template <class T>
T maxn(T arr[], int);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double dbls[4] = { 1.2 , 2.3 , 3.4 , 4.5};
	int ints[6] = { 1, 2, 3, 4, 5, 6};
	char * strings[5] = {"Herp", "the Derp", "Shoop", "Da Whoop", "Richmond"};
	cout << "Now printing the largest of the following real values: ";
	for(int i=0; i < 3; i++)
		cout << dbls[i] << ", ";
	cout << dbls[3];
	cout << endl << "Largest value is: " << maxn(dbls, 4) << endl;
	cout << "Now printing the largest of the following int values: ";
	for(int i=0; i < 5; i++)
		cout << ints[i] << ", ";
	cout << ints[5];
	cout << endl << "Largest value is: " << maxn(ints, 6) << endl;
	cout << "Now printing the longest of the following strings: ";
	for(int i=0; i < 4; i++)
		cout << strings[i] << ", ";
	cout << strings[4];
	cout << endl << "Longest string is: " << maxn(strings, 5) << endl;
	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// Takes an arry of items of type T as well as the size of the array 
// and returns the largest item in the array
template <class T>
T maxn(T arr[], int n)
{
	if (n<=0)
		return NULL;

	T ret = arr[0];
	for(int i=0; i < n; i++)
	{
		if (ret < arr[i])
			ret = arr[i];
	}
	return ret;
}

// specialization when dealing with an array of c-style strings
template <> const char * maxn<const char *>(const char * arr[], int n)
{
	
	if (n<=0)
		return NULL;

	const char* ret = arr[0];
	for(int i=0; i < n; i++)
	{
		if (strlen(ret) < strlen(arr[i]))
			ret = arr[i];
	}
	return ret;
}