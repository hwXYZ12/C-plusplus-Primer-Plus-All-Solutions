// chapter 6 exercise 8 - ch6e8.cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	using namespace std;

	string fname;
	cout << "Enter a file name: ";
	cin >> fname;

	ifstream file;
	file.open(fname);

	if (!file.is_open())
	{
		cout << "File could not be opened." << endl;
		cout << "Press ENTER to exit.";
		cin.get();
		cin.get();
		return 0;
	}

	char ch = file.get();
	int count = 0;
	while (ch != EOF)
	{
		++count;
		ch = file.get();
	}

	cout << "There are " << count << " characters in " << fname << endl;
	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}