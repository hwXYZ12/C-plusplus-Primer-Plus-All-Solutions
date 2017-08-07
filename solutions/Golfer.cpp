// Golfer.cpp - ch10e3
#include <iostream>;
#include "Golfer.h";

namespace GOLFER
{

	/* non-interactive version:
	   function sets golf structure to provided name, handicap
	   using values passed as arguments to the function
	*/
	Golfer::Golfer(const char * name, int hc)
	{
		// we'll use a manual string copy here
		for(int i=0; i < Len; i++)
		{
			fullname[i] = name[i];
			if ('\0' == name[i] )
				break;
		}
		// guarantees that the string is null-terminated
		fullname[Len-1] = '\0';

		// handicaps cannot be negative
		if (hc < 0)
			hc = 0;
		handicap = hc;
	}

	/* interactive version:
	   function solicits name and handicap from user
	   and sets the members of g to the values entered
	   returns 1 if name is entered, 0 if name is empty string
	*/
	int Golfer::setGolfer()
	{
		using std::cout;
		using std::endl;
		using std::cin;
		cout << "Please enter a name: ";
		cin.getline(fullname, Len);

		// End input if the name is an empty string
		if('\0' == fullname[0])
		{
			cout << "You've entered an empty name for your golfer!"
				 << endl << "Terminating input..." << endl;
			handicap = 0;

			return 0;
		}
		if (!cin && '\0' != fullname[0])
		{
			// In this case the user has entered some
			// input but the newline character has not been processed
			// implying that the user entered too many characters
			// so we must clear the input queue
			cin.clear();
			while(cin.get()!='\n');
		}

		int temp = 0;
		cout << "Please enter a handicap: ";
		cin >> temp;
		if (!cin || temp<0)
		{
			cout << "ERROR - That's not a positive integer!"
				 << "\nUsing default handicap of 0." << endl;

			// Actually set the handicap
			// as claimed in the error message
			handicap = 0;

			// Clear input
			cin.clear();
			while(cin.get() != '\n');
		} else 
		{
			handicap = temp;
			// Clear input
			cin.get();
		}

		return 1;
	}

	// function resets handicap to new values
	void Golfer::setHandicap(int hc)
	{
		if (hc > 0)
			handicap = hc;
	}

	// function displays contents of golf structure
	void Golfer::showGolf() const
	{
		using std::endl;
		using std::cout;
		cout << "Golfer: " << fullname << endl
			 << "Handicap: " << handicap << endl;
	}

}