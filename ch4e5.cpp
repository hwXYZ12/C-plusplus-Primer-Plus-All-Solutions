// chapter 4 exercise 5 - ch4e5.cpp
#include <iostream>
#include <string>

struct CandyBar
{
	std::string name;
	double weight;
	int calories;
};

int main()
{
	using namespace std;
	CandyBar snack = 
	{
		"Mocha Munch",
		2.3,
		350
	};
	cout << "Here are some details about a particular candybar!\n";
	cout << "Name: " << snack.name << endl;
	cout << "Weight: " << snack.weight << endl;
	cout << "Calories: " << snack.calories << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}