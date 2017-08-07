// chapter 8 exercise 3 - ch8e3.cpp
#include <iostream>
#include <string>
#include <cctype>

// constants
const int LIMIT = 3000;

// changes the characters in a string object to all caps
void toUpperCase(std::string &);


int main()
{
	
	using namespace std;

	/* We'll run a loop to prompt the user for
	   some arbitrary input. Our program will
	   display the input in all caps back to the
	   user and loop again.
	*/ 

	string temp;
	cout << "Enter a string (q to quit): ";
	getline(cin, temp);
	while(temp[0]!='q'||temp[1]!='\0')
	{
		toUpperCase(temp);
		cout << temp << endl;

		// start the loop again
		cout << "Enter a string (q to quit): ";
		getline(cin, temp);
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// changes the characters in a string object to all caps
void toUpperCase(std::string & s)
{
	int i=0;
	while(s[i])
	{
		s[i] = toupper(s[i]);
		i++;
	}
}