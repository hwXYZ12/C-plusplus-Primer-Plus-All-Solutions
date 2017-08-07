// chapter 4 exercise 9 - ch4e9.cpp
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
	cout << "Calories: " << (*candybar).calories << " cal" << endl;
}

int main()
{
	using namespace std;
	int n = 3;
	CandyBar * snacks = new CandyBar[n];
	snacks[0].name = "Herp";
	snacks[0].weight = 5.0;
	snacks[0].calories = 5000;
	snacks[1].name = "Derp";
	snacks[1].weight = 1.0;
	snacks[1].calories = 200;
	snacks[2].name = "Shoop Da Whoop";
	snacks[2].weight = 20.0;
	snacks[2].calories = 20000;
	displayCandyBar(&snacks[0]);
	displayCandyBar(&snacks[1]);
	displayCandyBar(&snacks[2]);
	cout << "Press ENTER to exit." << endl;
	delete [] snacks;
	cin.get();
	return 0;
}