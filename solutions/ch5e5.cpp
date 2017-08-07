// chapter 5 exercise 5 - ch5e5.cpp
#include <iostream>
#include <string>
const std::string months[12] = 
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

int main()
{
	using namespace std;
	int sales[12];
	cout << "Enter book sales for each month of the year.\n";
	for(int i=0; i<12; ++i)
	{
		cout << months[i] << ": ";
		cin >> sales[i];
	}
	int sum=0;
	for(int i=0; i<12; ++i)
		sum+=sales[i];
	cout << "Your total sales this year is " << sum << " books!\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}