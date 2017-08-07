// chapter 6 exercise 1 - ch6e1.cpp
#include <iostream>
#include <cctype>

int main()
{
	using namespace std;

	cout << "Enter some text and terminate it with an @ character.\n";
	char ch;
	while( (cin.get(ch)) && ch != '@')
	{
		if (isalpha(ch))
			if (isupper(ch))
				ch = tolower(ch);
			else
				ch = toupper(ch);
		cout << ch;
	}
	
	// Clear input
	while (cin.get() != '\n');

	cout << "\nPress ENTER to exit." << endl;
	cin.get();
	return 0;
}