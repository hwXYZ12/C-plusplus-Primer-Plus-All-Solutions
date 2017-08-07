// chapter 4 exercise 1 - ch4e1.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "What is your first name? ";
	string fname, lname;
	char expg;
	int age;
	getline(cin, fname); 
	cout << "What is your last name? ";
	getline(cin, lname);
	cout << "What grade do you deserve? ";
	cin >> expg;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << lname << ", " << fname << endl;
	cout << "Grade: " << char (expg+1) << endl;
	cout << "Age: " << age << endl;
	cout << "Please press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}