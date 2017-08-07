// chapter 8 exercise 1 - ch8e1.cpp
#include <iostream>

// global variables
int derpCount = 0;

// constants
const int LIMIT = 100;

// function derp intended to print a string. If the function derp is called
// with a second nonzero integer argument then the function prints the string
// a number of times equal to the number of times derp has already been called
// throughout the lifetime of the program.
void derp(const char *, int n=0);

int main()
{
	
	using namespace std;

	/* We'll run a loop to prompt the user for
	   a message as well as an integer in order to test
	   our derp function.
	*/ 
	char msg[LIMIT];
	int x;
	cout << "Please enter a message (q to quit): ";
	cin.getline(msg, LIMIT);
	while(msg[0]!='q')
	{
		cout << "Please enter an integer: ";
		cin >> x;
		while (!cin)
		{
			cout << "That's not an integer! Please enter an integer: ";

			// toggle checkbit and clear input queue
			cin.clear();
			while(cin.get()!='\n');
			cin >> x;
		}
		cout << "Now executing test function with the given parameters..." << endl;
		derp(msg, x);

		// toggle checkbit and clear input queue
		cin.clear();
		while(cin.get()!='\n');

		// start the loop again
		cout << "Please enter a message (q to quit): ";
		cin.getline(msg, LIMIT);
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// function derp intended to print a string. If the function derp is called
// with a second nonzero integer argument then the function prints the string
// a number of times equal to the number of times derp has already been called
// throughout the lifetime of the program.
void derp(const char * msg, int n)
{
	using namespace std;
	if (0 == n)
	{
		cout << msg << endl;
		derpCount++;
		return;
	}

	// when given a nonzero integer argument
	// print the given message a number of times
	// equal to the number of times derp has been called
	// during the programs lifetime
	for(int i=0; i < derpCount; i++)
	{
		cout << msg << endl;
	}
	derpCount++;
}