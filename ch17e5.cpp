// chapter 17 exercise 5 - ch17e5.cpp
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
#include <algorithm>;

using namespace std;

int main()
{	
	string matDat = "mat.dat";
	ifstream ifstream1;
	ifstream1.open(matDat);
	if(!ifstream1.good())
	{
		cout << "A fatal error has occurred. Press ENTER to exit.";
		cin.get();
		return 0;
	}

	string patDat = "pat.dat";
	ifstream ifstream2;
	ifstream2.open(patDat);
	if(!ifstream2.good())
	{
		cout << "A fatal error has occurred. Press ENTER to exit.";
		cin.get();
		return 0;
	}
	
	string matnpatDat = "matnpat.dat";
	ofstream ofstream1;
	ofstream1.open(matnpatDat);
	if(!ofstream1.good())
	{
		cout << "A fatal error has occurred. Press ENTER to exit.";
		cin.get();
		return 0;
	}


	// get data from mat.dat and pat.dat
	string temp;
	vector<string> matsFriends, patsFriends;
	while(!ifstream1.eof())
	{
		getline(ifstream1, temp);
		matsFriends.push_back(temp);
	}
	sort(matsFriends.begin(), matsFriends.end());
	cout << "Mats Friends: " << endl;
	for(string x: matsFriends)
		cout << x << endl;
	while(!ifstream2.eof())
	{
		getline(ifstream2, temp);
		patsFriends.push_back(temp);
	}
	sort(patsFriends.begin(), patsFriends.end());
	cout << "Pats Friends: " << endl;
	for(string x: patsFriends)
		cout << x << endl;
	
	unique(matsFriends.begin(), matsFriends.end());
	unique(patsFriends.begin(), patsFriends.end());

	vector<string> allFriends(matsFriends.size()+patsFriends.size());
	merge(matsFriends.begin(), matsFriends.end(), patsFriends.begin(), patsFriends.end(), allFriends.begin());
	sort(allFriends.begin(), allFriends.end());
	unique(allFriends.begin(), allFriends.end());
	
	vector<string> trimFriends;
	for(string x: allFriends)
		if(find(trimFriends.begin(), trimFriends.end(), x)==trimFriends.end())
			trimFriends.push_back(x);
	allFriends.clear();

	cout << "Mats & Pats Friends: " << endl;
	ofstream1 << "Mats & Pats Friends: " << endl;
	for(string x: trimFriends)
	{
		cout << x << endl;
		ofstream1 << x << endl;
	}
	cout << "Mats & Pats Friends stored in 'matnpat.dat'." << endl;
	
	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}