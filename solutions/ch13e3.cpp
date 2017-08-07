// chapter 13 exercise 3 - ch13e3.cpp
#include <iostream>;
#include <string>;
#include "dma.h";
const int TEST_NUM = 4;
const int LIM = 80;

// helper function
bool checkInput();

int main()
{
	using DMA::baseDMA;
	using DMA::hasDMA;
	using DMA::lacksDMA;
	using DMA::DMAABC;
	using std::cout;
	using std::cin;
	using std::endl;
	DMAABC * p_test[TEST_NUM];
	char temp[LIM];
	int tempnum;
	char type;

	for ( int i = 0; i < TEST_NUM; ++i)
	{
		cout << "Enter DMA Object label: ";
		cin >> temp;

		if (!checkInput())
			return 0;

		// clear input queue
		while (cin.get() != '\n');

		cout << "Enter DMA Object rating: ";
		cin >> tempnum;

		if (!checkInput())
			return 0;

		// clear input queue
		while (cin.get() != '\n');

		cout << "Enter one of the following menu choices... " << endl
			 << "A: 'baseDMA' object" << endl
			 << "B: 'lacksDMA object" << endl
			 << "C: 'hasDMA' object" << endl
			 << "Your choice: ";

		// get first choice
		cin >> type;
		
		// query user until a valid choice is received
		while (type != 'A' && type != 'B' && type != 'C')
		{
			cout << "Please enter either A, B, or C: ";

			// get next choice
			cin >> type;
			if (!checkInput())
				return 0;
		
		}
		
		char temp2[LIM];

		// switch routines based on choice
		switch (type)
		{
		case 'A':
			p_test[i] = new baseDMA(temp, tempnum);
			break;
		case 'B':
			cout << "Enter a color: ";
			cin >> temp2;

			p_test[i] = new lacksDMA(temp2, temp, tempnum);
			break;
		case 'C':
			cout << "Enter a style: ";
			cin >> temp2;

			p_test[i] = new hasDMA(temp2, temp, tempnum);
			break;
		}

		// clear input queue
		while (cin.get() != '\n');

	} // for loop

	// display the created objects
	cout << endl;
	cout << "Your objects: " << endl << endl;
	for (int i=0; i < TEST_NUM; ++i)
	{
		p_test[i]->view();
		cout << endl;
	}

	for (int i=0; i < TEST_NUM; ++i)
	{
		delete p_test[i];	// free memory
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}


// helper function
bool checkInput()
{
	using std::cin;
	using std::cout;
	using std::endl;
	if (!cin)
	{
		cout << "An error has occurred, the program will now terminate.";

		cin.clear();
		while (cin.get() != '\n');

		cout << "Press ENTER to exit.";
		cin.get();
		return false;
	}
	return true;
}
