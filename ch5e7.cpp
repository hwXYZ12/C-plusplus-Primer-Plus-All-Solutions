// chapter 5 exercise 7 - ch5e7.cpp
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	struct car
	{
		string make;
		int year;
	};

	int n;
	cout << "How many cars would you like to catalog? ";
	cin >> n; 
	cin.get();
	car* cars = new car[n];
	for(int i=0; i<n; ++i)
	{
		cout << "Car #" << i+1 << "\n";
		cout << "Please enter the make: ";
		getline(cin, cars[i].make);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
		cin.get();
	}
	cout << "Here is your collection!" << endl;
	for(int i=0; i<n; ++i)
		cout << cars[i].year << " " << cars[i].make << endl;

	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}