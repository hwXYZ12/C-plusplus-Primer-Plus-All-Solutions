// chapter 9 exercise 2 - ch9e2.cpp
#include <iostream>;
#include <string>;

// function prototype 
void strcount(std::string);

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;
	string input;

	cout << "Enter a line:\n";
	getline(cin, input);

	while(input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}

void strcount(std::string str)
{
	using std::cout;
	using std::endl;
	static int total = 0;
	int count = 0;
	cout << "\"" << str << "\" contains ";
	count = str.length();
	total += count;
	cout << count << " characters" << endl
		 << total << " characters total" << endl;
}