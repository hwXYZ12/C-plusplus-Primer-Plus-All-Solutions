// chapter 6 exercise 3 - ch6e3.cpp
#include <iostream>
#include <cctype>

int main()
{
	using namespace std;

	cout << "Please enter one of the following choices: \n";
	cout << "c) carnivore			p) pianist\n";
	cout << "t) tree				g) game\n";
	cout << "Please enter a c, p, t, or g: ";

	char ch;
	bool gameOver = false;
	while (cin >> ch)
	{
		switch (ch)
		{
			case 'C':
			case 'c': cout << "Nom nom nom....";
					  break;
			case 'p':
			case 'P': cout << "herp";
					  break;
			case 't':
			case 'T': cout << "One, Two, Forest!";
					  break;
			case 'g':
			case 'G': cout << "Game Over.";
					  gameOver = true;
					  break;
			default: ;
		}
		if (!gameOver)
			cout << "\nPlease enter a c, p, t, or g: ";
		else
			break;
	}
	
	cout << "\nPress ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}