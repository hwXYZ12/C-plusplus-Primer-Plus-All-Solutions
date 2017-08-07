// chapter 17 exercise 4 - ch17e4.cpp
#include <iostream>;
#include <fstream>;
#include <string>;

int main()
{
	using namespace std;
	

	string temp;
	ifstream ifstream1;
	cout << "Please enter the first filepath to be used as input: ";
	getline(cin, temp);
	ifstream1.open(temp);
	while(!ifstream1.good())
	{
		ifstream1.clear();
		cout << "The file couldn't be opened. Please enter another filepath: ";
		getline(cin, temp);
		ifstream1.open(temp);
	}

	cout << "Please enter the second filepath to be used as input: ";
	ifstream ifstream2;
	getline(cin, temp);
	ifstream2.open(temp);
	while(!ifstream2.good())
	{
		ifstream2.clear();
		cout << "The file couldn't be opened. Please enter another filepath: ";
		getline(cin, temp);
		ifstream2.open(temp);
	}

	ofstream ofstream1;
	cout << "Please enter a filepath to be used as output: ";
	getline(cin, temp);
	ofstream1.open(temp);
	while(!ofstream1.good())
	{
		ofstream1.clear();
		cout << "The file couldn't be opened. Please enter another filepath: ";
		getline(cin, temp);
		ofstream1.open(temp);
	}

	// get a line from input 1 and a line from input 2
	// and concatenate them using a space ' ' as a separator
	// and write the result to the output file
	string temp2;
	while(!ifstream1.eof()&&!ifstream2.eof())
	{
		getline(ifstream1, temp);
		getline(ifstream2, temp2);
		ofstream1 << temp + " " + temp2 << endl;
	}

	// if file 1 is shorter than file 2 then we will
	// get the rest of the lines from file 2 and
	// write them to the output
	temp = temp2 = "";
	while(ifstream1.eof()&&!ifstream2.eof())
	{
		getline(ifstream2, temp);
		ofstream1 << temp << endl;
	}

	// if file 1 is longer than file 2 then we will
	// get the rest of the lines from file 1 and
	// write them to the output
	temp = temp2 = "";
	while(!ifstream1.eof()&&ifstream2.eof())
	{
		getline(ifstream1, temp);
		ofstream1 << temp << endl;
	}

	// finally we've reached eof for both
	// input files and can quit the program
	cout << "Mission accomplished. Press ENTER to exit.";
	cin.get();
	return 0;
}