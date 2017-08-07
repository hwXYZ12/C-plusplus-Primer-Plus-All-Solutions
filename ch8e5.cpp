// chapter 8 exercise 5 - ch8e5.cpp
#include <iostream>;

// Takes an arry of five items of type T and returns the largest
// item in the array
template <class T>
T max5(T arr[5]);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double dbls[5] = { 1.2 , 2.3 , 3.4 , 4.5, 5.6};
	int ints[5] = { 1, 2, 3, 4, 5};
	cout << "Now printing the largest of the following real values: ";
	for(int i=0; i < 5; i++)
		cout << dbls[i] << " ";
	cout << endl << "Largest value is: " << max5(dbls) << endl;
	cout << "Now printing the largest of the following int values: ";
	for(int i=0; i < 5; i++)
		cout << ints[i] << " ";
	cout << endl << "Largest value is: " << max5(ints) << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// Takes an arry of five items of type T and returns the largest
// item in the array
template <class T>
T max5(T arr[5])
{
	T ret = arr[0];
	for(int i=0; i < 5; i++)
	{
		if (ret < arr[i])
			ret = arr[i];
	}
	return ret;
}