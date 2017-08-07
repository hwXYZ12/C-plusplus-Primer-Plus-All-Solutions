// chapter 17 exercise 1 - ch17e1.cpp
#include <iostream>;
#include <string>;

int main()
{
	using namespace std;

	string text;
	cout << "Enter some text that contains a '$' character: ";
	getline(cin, text, '$');
	cout << "There are " << text.size() << " character(s) between the beginning"
		 << endl << "of the input text and the first '$' symbol" << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}