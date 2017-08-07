// chapter 17 exercise 6 - ch17e6.cpp
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
#include "emp.h";

static const char * DATA_FILE = "C:\\Users\\William\\Documents\\Visual Studio 2012\\Projects\\exerciseProject\\Debug\\workingData.txt";

using namespace std;
using namespace EMPLOYEES;

int main()
{
	// open working data file
	ifstream inData;
	inData.open(DATA_FILE);
	if(!inData.good())
	{
		cout << "ERROR - A vital data file couldn't be opened. Press ENTER to exit.";
		cin.get();
		return 0;
	}

	// read in data from opened file
	// we'll use a vector of pointers to abstr_emp
	// and dynamically allocate data for each object
	// found in the input file and create the object
	// on the spot
	vector<abstr_emp *> emps;
	string temp[4];
	int tempNum, which;
	while(inData >> which && !inData.eof())
	{
		// the format of the input file is such that we will take
		// a character to determine which employee object to load
		inData.get();
		switch (which)
		{
		case Employee:
			// get first name, last name, and job
			getline(inData, temp[0]);
			getline(inData, temp[1]);
			getline(inData, temp[2]);
			emps.push_back(new employee(temp[0], temp[1], temp[2]));
			break;
		case Manager:
			// get first name, last name, and job
			// as well as how many people this employee is in charge of
			getline(inData, temp[0]);
			getline(inData, temp[1]);
			getline(inData, temp[2]);
			inData >> tempNum;
			inData.get();
			emps.push_back(new manager(temp[0], temp[1], temp[2], tempNum));
			break;
		case Fink:
			// get first name, last name, and job
			// as well as who this employee reports to
			getline(inData, temp[0]);
			getline(inData, temp[1]);
			getline(inData, temp[2]);
			getline(inData, temp[3]);
			emps.push_back(new fink(temp[0], temp[1], temp[2], temp[3]));
			break;
		case Highfink:
			// get first name, last name, and job
			// as well as how many people this employee is in charge of
			// as well as who this employee reports to
			getline(inData, temp[0]);
			getline(inData, temp[1]);
			getline(inData, temp[2]);
			getline(inData, temp[3]);
			inData >> tempNum;
			inData.get();
			emps.push_back(new highfink(temp[0], temp[1], temp[2], temp[3], tempNum));
			break;
		default:
			cout << "ERROR - Couldn't read the input file. Critical input file may have been corrupted!" << endl;
			break;
		}
	} // while(!inData.eof())
	
	// now we want to display what we've got so far
	for(abstr_emp * x : emps)
	{
		x->showAll();
		cout << endl;
	}

	// take input from the user to add to the data file
	char choice;
	abstr_emp * e = nullptr;
	choice = 'a';
	cout << "Please enter data you'd like added to the data file." << endl;
	while(choice!='q')
	{
		cout << "Enter a menu option to begin entering data: " << endl;
		cout << "a: employee" << endl
			 << "b: manager" << endl
			 << "c: fink" << endl
			 << "d: highfink" << endl
			 << "q: quit" << endl
		     << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			e = new employee;
			break;
		case 'b':
			e = new manager;
			break;
		case 'c':
			e = new fink;
			break;
		case 'd':
			e = new highfink;
			break;
		case 'q':
			e = nullptr;
			cout << "Finished entering data." << endl << endl;
			break;
		default:
			e = nullptr;
			cout << "Unknown selection. Please enter a selection from the menu below." << endl;
			break;
		}
		// clear any characters after the first
		while(cin.get()!='\n');
		if (e!=nullptr)
		{
			e->setAll();
			emps.push_back(e);
		}
	} // while(which!='q')

	// display all data again
	for(abstr_emp * x : emps)
	{
		x->showAll();
		cout << endl;
	}


	// write all the data to the file
	ofstream outData;
	outData.open(DATA_FILE);
	if(!outData.good())
	{
		cout << "ERROR - A fatal error has occurred. Press ENTER to exit.";
		cin.get();
		return 0;
	}
	for(abstr_emp * x : emps)
	{
		x->writeAll(outData);
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}