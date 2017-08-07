// chapter 4 exercise 2 - ch4e2.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std;
	cout << "Enter your name:\n";
	string name, dessert;
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you " << name << ".\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}