// chapter 17 exercise 3 - ch17e3.cpp
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
		if (!cin)
		{
			cerr << "Something terrible has happened." << endl
				 << "Now terminating process..." << endl;
		}
	}
	return 0;
}