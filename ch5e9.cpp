// chapter 5 exercise 9 - ch5e9.cpp
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string word;

	cout << "Enter words (to stop, type the word done):\n";
	cin >> word;
	int count = 0;
	while (word != "done")
	{
		++count;
		cin >> word;
	}
	cout << "You have entered a total of " << count << " words, not including \"done\".\n";
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}