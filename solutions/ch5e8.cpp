// chapter 5 exercise 8 - ch5e8.cpp
#include <iostream>
#include <cstring>
const int MAX_CHARS = 8000;

int main()
{
	using namespace std;
	char word[MAX_CHARS] = {0};

	cout << "Enter words (to stop, type the word done):\n";
	cin >> word;
	int count = 0;
	while (strcmp(word, "done"))
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