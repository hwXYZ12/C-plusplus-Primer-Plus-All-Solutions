// chapter 9 exercise 1 - ch9e1.cpp
#include <iostream>;
#include "golf.h";

const int NUM_OF_PLAYERS = 4;
int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	golf players[NUM_OF_PLAYERS];
	setGolf(players[0], "Herp the Derp", 1);

	// Loops through each player and retrieves
	// information on each from the user.
	// The loop terminates when either all 
	// of the players have been registered
	// or the user enters a blank name for a player
	int i = 1;
	while(i < NUM_OF_PLAYERS && setGolf(players[i]))
	{
		i++;
	}
	// The value of i is now the number of golfers successfully
	// registered.


	cout << "The handicap of the 1st player has been adjusted"
		 << endl << "to 10." << endl;
	handicap(players[0], 10);

	cout << "Now displaying each registered player..." << endl;
	for(int j=0; j < i; j++)
	{
		showGolf(players[j]);
		cout << endl;
	}

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}