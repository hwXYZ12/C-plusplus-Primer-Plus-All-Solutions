// chapter 6 exercise 6 - ch6e6.cpp
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	struct contributor
	{
		string name;
		double amount;
	};

	cout << "Please enter the number of contributors to the Society for the Preservation of Rightful Influence: ";

	int n=0;
	while (!(cin >> n))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Please enter an integer: ";
	}

	// Clear input queue after numerical input
	while (cin.get() != '\n');

	contributor* contributors = new contributor[n];

	for(int i=0; i < n; ++i)
	{
		cout << "Please enter the name of Contributor " << i+1 << ": ";
		getline(cin, contributors[i].name);
		cout << "Please enter the amount " << contributors[i].name << " has contributed: ";
		while (!(cin >> contributors[i].amount))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Please enter a numerical value for the amount contributed: ";
		}

		// Clear input queue after numerical input
		while (cin.get() != '\n');
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
	return 0;
}