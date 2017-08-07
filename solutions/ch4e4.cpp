// chapter 4 exercise 4 - ch4e4.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "Enter your first name: ";
	string fname, lname, comb;
	getline(cin, fname);
	cout << "Enter your last name: ";
	getline(cin, lname);
	comb = lname + ", " + fname;
	cout << "Here's the information in a single string: " << comb << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}