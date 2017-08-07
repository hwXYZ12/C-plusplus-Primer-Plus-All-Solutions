// chapter 12 exercise 2 - ch12e2.cpp
#include <iostream>;
#include "string2.h";
using namespace std;

int main()
{
	using STRING2::String;
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;					// overloaded << operator
	cin >> s3;					// overloaded >> operator
	s2 = "My name is " + s3;	// overloaded =, + operator
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();				// converts string to uppercase
	cout << "The string\n" << s2 << "\ncontains " << s2.occurs('A')
		 << " 'A' characters in it.\n";
	s1 = "red";					// String(const char *)
								// then String & operator=(const String&)
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();		// converts string to lowercase
		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])	// overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Cya later!\n";

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}