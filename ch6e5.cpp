// chapter 6 exercise 5 - ch6e5.cpp
#include <iostream>

int main()
{
	using namespace std;

	cout << "Please enter your income in tvarps and we will compute the taxes you owe." << endl;
	cout << "Enter any non-numeric input or a negative number to exit." << endl;
	cout << "Income (tvarps): ";

	double income=0, sum=0;
	while (cin >> income && income >= 0)
	{	
		if (income < 5000)
			sum=0;
		else if (income >= 5000 && income < 15000)
			sum=(income-5000)*.10;
		else if (income >= 15000 && income < 35000)
			sum=(income-15000)*.15 + 10000*.10;
		else
			sum=(income-35000)*.2 + 20000*.15 + 10000*.1;
		cout << "You owe a total of " << sum << " tvarps in taxes.";
		cout << "\nIncome (tvarps): ";
	}
	
	cout << "Press ENTER to exit.";
	if (!cin)
	{
		cin.clear();
		cin.get();
	}
	cin.get();
	cin.get();
	return 0;
}