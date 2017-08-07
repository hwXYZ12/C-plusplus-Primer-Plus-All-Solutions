// chapter 17 exercise 2 - ch17e2.cpp
#include <iostream>;
#include <fstream>;
#include <string>;

int main()
{
	using namespace std;
	
	string temp;
	while(!cin.eof())
	{
		getline(cin, temp);
		cout << temp << endl;
	}

	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}