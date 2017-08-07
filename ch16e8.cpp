// chapter 16 exercise 8 - ch16e8.cpp
#include <iostream>;
#include <vector>;
#include <string>;
#include <algorithm>;
using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;


// helper function used to retrieve a list of
// names from the user
vector<string> & getNames(vector<string> & list)
{
	string temp;
	cout << "Enter a name <q to quit>: ";
	getline(cin, temp);
	while(temp != "q")
	{
		cout << "The name " << temp << " has been added." << endl;
		list.push_back(temp);
		cout << "Enter a name <q to quit>: ";
		getline(cin, temp);
	}
	cout << "Name entry completed." << endl;
	return list;
}


int main()
{
	using std::sort;
	using std::merge;
	using std::unique;
	vector<string> l1, l2, l3;
	cout << "Please enter a list of Mats friends." << endl;
	getNames(l1);
	// sort, remove duplicates, and display the names obtained
	sort(l1.begin(), l1.end());
	unique(l1.begin(), l1.end());
	cout << "Mats friends: " << endl;
	for(string x : l1)
		cout << x << endl;

	cout << "Please enter a list of Pats friends." << endl;
	getNames(l2);
	// sort, remove duplicates, and display the names obtained
	sort(l2.begin(), l2.end());
	unique(l2.begin(), l2.end());
	cout << "Pats friends: " << endl;
	for(string x : l2)
		cout << x << endl;

	// merge, sort, remove duplicates, and display the names 
	// of both Mats friends and Pats friends
	l3.resize(l1.size() + l2.size());
	merge(l1.begin(), l1.end(), l2.begin(), l2.end(), l3.begin());
	sort(l3.begin(), l3.end());
	unique(l3.begin(), l3.end());
	cout << "Mats & Pats friends: ";
	for(string x : l3)
		cout << x << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}