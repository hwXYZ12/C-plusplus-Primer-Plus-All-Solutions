// chapter 4 exercise 8 - ch4e8.cpp
#include <iostream>
#include <string>

struct PizzaInfo
{
	std::string company;
	double weight;
	double diameter;
};

void displayPizzaInfo(PizzaInfo * p)
{
	using namespace std;
	cout << "Here are some details about a particular pizza place and their pizza!\n";
	cout << "Company Name: " << p->company << endl;
	cout << "Weight: " << p->weight << " lbs." << endl;
	cout << "Diameter: " << p->diameter << " in." << endl;
}

int main()
{
	using namespace std;
	PizzaInfo p;
	cout << "Enter the diameter of a company's pizza: ";
	cin >> p.diameter;
	cout << "Enter the name of this particular pizza company: ";
	cin.get();
	getline(cin, p.company);
	cout << "Enter the weight of this company's pizza: ";
	cin >> p.weight;
	displayPizzaInfo(&p);
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}