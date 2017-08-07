// chapter 6 exercise 9 - ch6e9.cpp
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	using namespace std;

	struct contributor
	{
		string name;
		double amount;
	};

	cout << "Please enter the file name that contains the list of contributors to the Society for the Preservation of Rightful Influence: ";

	string fname;
	cin >> fname;
	ifstream file;
	file.open(fname);
	
	if(!file.is_open())
	{
		cout << "File could not be opened." << endl;
		cout << "Press ENTER to exit.";
		cin.get();
		cin.get();
		return 0;
	}

	int n=0;
	if (!(file >> n))
	{
		cout << "ERROR - File format could not be read; missing number of contributors." << endl;
		cout << "Press ENTER to exit.";
		cin.get();
		return 0;
	}

	// Clear input queue after numerical input
	while (file.get() != '\n');

	contributor* contributors = new contributor[n];

	char temp;
	for(int i=0; i < n; ++i)
	{
		getline(file, contributors[i].name);
		if (!(file >> contributors[i].amount))
		{
			cout << "ERROR - File format could not be read; missing a contribution value at location " << i+1 << ".\n";
			cout << "Press ENTER to exit.";
			cin.get();
			return 0;
		}

		// Clear input queue after numerical input
		// We may reach EOF during this loop, in which case we have an additional exit
		// condition for the loop
		temp = file.get();
		while (temp != '\n' && temp != EOF)
		{
			temp = file.get();
		}
	}

	cout << "Grand Patrons:" << endl;
	bool atleast1 = false;
	for(int i=0; i < n; ++i)
	{
		if (contributors[i].amount >= 10000)
		{
			cout << contributors[i].name << ", $" << contributors[i].amount << endl;
			atleast1 = true;
		}
	}
	if (false == atleast1)
		cout << "None" << endl;

	
	cout << "Patrons:" << endl;
	atleast1 = false;
	for(int i=0; i < n; ++i)
	{
		if (contributors[i].amount < 10000)
		{
			cout << contributors[i].name << ", $" << contributors[i].amount << endl;
			atleast1 = true;
		}
	}
	if (false == atleast1)
		cout << "None" << endl;

	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}