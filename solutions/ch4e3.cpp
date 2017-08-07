// chapter 4 exercise 3 - ch4e3.cpp
#include <iostream>
#include <cstring>
const int MAX_LENGTH_OF_NAME = 20;
int main()
{
	using namespace std;
	cout << "Enter your first name: ";
	char fname[MAX_LENGTH_OF_NAME], lname[MAX_LENGTH_OF_NAME];
	char comb[2*MAX_LENGTH_OF_NAME+2];
	cin.getline(fname, MAX_LENGTH_OF_NAME);
	cout << "Enter your last name: ";
	cin.getline(lname, MAX_LENGTH_OF_NAME);
	strncpy_s(comb, lname, MAX_LENGTH_OF_NAME);
	strncat_s(comb, (char *) ", ", 2);
	strncat_s(comb, fname, MAX_LENGTH_OF_NAME);
	cout << "Here's the information in a single string: " << comb << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}