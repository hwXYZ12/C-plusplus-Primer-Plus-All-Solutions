// chapter 6 exercise 7 - ch6e7.cpp
#include <iostream>
#include <string>
#include <cctype>

int main()
{
	using namespace std;

	cout << "Enter words (q to quit):\n";

	string word;
	char ch;
	int vowels, consonants, other;
	vowels = consonants = other = 0;
	while (cin >> word)
	{
		if ("q" == word)
			break;
		ch = word[0];
		if (isalpha(ch))
			switch (ch)
			{
				case 'a':
				case 'A': ++vowels;
						  break;
				case 'e':
				case 'E': ++vowels;
						  break;
				case 'i':
				case 'I': ++vowels;
						  break;
				case 'o':
				case 'O': ++vowels;
						  break;
				case 'u':
				case 'U': ++vowels;
						  break;
				case 'y':
				case 'Y': ++vowels;
						  break;
				default:
						++consonants;
			}
		else
			++other;
	}

	
	cout << vowels << " word(s) beginning with vowels" << endl;
	cout << consonants << " word(s) beginning with consonants" << endl;
	cout << other << " others" << endl;
	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}