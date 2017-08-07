// chapter 4 exercise 6 - ch4e6.cpp
#include <iostream>
#include <string>

struct CandyBar
{
	std::string name;
	double weight;
	int calories;
};

void displayCandyBar(CandyBar * candybar)
{
	using namespace std;
	cout << "Here are some details about a particular candybar!\n";
	cout << "Name: " << (*candybar).name << endl;
	cout << "Weight: " << (*candybar).weight << " oz." << endl;
	cout << "Calories: " << (*candybar).calories << endl;
}

int main()
{
	using namespace std;
	CandyBar snacks[3] =
	{
		{"Herp", 5.0, 5000},
		{"Derp", 1.0, 200},
		{"Shoop Da Whoop", 20.0, 20000}
	};
	displayCandyBar(&snacks[0]);
	displayCandyBar(&snacks[1]);
	displayCandyBar(&snacks[2]);
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}