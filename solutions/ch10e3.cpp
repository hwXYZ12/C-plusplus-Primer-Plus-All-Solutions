// chapter 10 exercise 3 - ch10e3.cpp
#include <iostream>;
#include "Golfer.h";

// globals
namespace 
{
	const int NUM_OF_PLAYERS = 4;
}

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using GOLFER::Golfer;

	Golfer players[NUM_OF_PLAYERS];
	players[0] = Golfer("Herp the Derp", 1); // uses default memberwise copying to set players[0], but this is fine for this example

	// Loops through each player and retrieves
	// information on each from the user.
	// The loop terminates when either all 
	// of the players have been registered
	// or the user enters a blank name for a player
	int i = 1;
	while(i < NUM_OF_PLAYERS && players[i].setGolfer())
	{
		i++;
	}
	// The value of i is now the number of golfers successfully
	// registered.


	cout << "The handicap of the 1st player has been adjusted"
		 << endl << "to 10." << endl;
	players[0].setHandicap(10);

	cout << "Now displaying each registered player..." << endl;
	for(int j=0; j < i; j++)
	{
		players[j].showGolf();
		cout << endl;
	}

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}