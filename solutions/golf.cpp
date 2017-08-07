// golf.cpp for ch9e1
#include <iostream>;
#include "golf.h";

/* non-interactive version:
   function sets golf structure to provided name, handicap
   using values passed as arguments to the function
*/
void setGolf(golf & g, const char * name, int hc)
{
	// since stcpy can be bugged
	// we'll use a manual string copy here
	for(int i=0; i < Len; i++)
	{
		g.fullname[i] = name[i];
		if ('\0' == name[i] )
			break;
	}
	// guarantees that the string is null-terminated
	g.fullname[Len-1] = '\0';
	g.handicap = hc;
}

/* interactive version:
   function solicits name and handicap from user
   and sets the members of g to the values entered
   returns 1 if name is entered, 0 if name is empty string
*/
int setGolf(golf & g)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "Please enter a name: ";
	cin.getline(g.fullname, Len);

	// End input if the name is an empty string
	if('\0' == g.fullname[0])
	{
		cout << "You've entered an empty name for your golfer!"
			 << endl << "Terminating input..." << endl;
		g.handicap = 0;

		return 0;

	}
	if (!cin && '\0' != g.fullname[0])
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
		g.handicap = 0;

		// Clear input
		cin.clear();
		while(cin.get() != '\n');
	} else 
	{
		g.handicap = temp;
		// Clear input
		cin.get();
	}

	return 1;

}

// function resets handicap to new values
void handicap(golf & g, int hc)
{
	if (hc > 0)
		g.handicap = hc;
}

// function displays contents of golf structure
void showGolf(const golf & g)
{
	using std::endl;
	using std::cout;
	cout << "Golfer: " << g.fullname << endl
		 << "Handicap: " << g.handicap << endl;
}