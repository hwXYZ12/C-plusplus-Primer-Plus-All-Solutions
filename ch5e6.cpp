// chapter 5 exercise 6 - ch5e6.cpp
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
	int sales[3][12], sum[3] = {0};
	for(int i=0; i<3; ++i)
	{
		cout << "Enter book sales for each month of the year. This will be your sales total for Year " << i+1 << ".\n";
		for(int j=0; j<12; ++j)
		{
			cout << months[j] << ": ";
			cin >> sales[i][j];
		}
		for(int j=0; j<12; ++j)
			sum[i]+=sales[i][j];
		cout << "Your total sales for Year " << i+1 << " is " << sum[i] << " books!\n";
	}
	int s=0;
	for(int i=0; i<3; ++i)
		s += sum[i];
	cout << "Your total sales for the past 3 years is " << s << " books!\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}