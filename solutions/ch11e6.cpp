// chapter 11 exercise 6 - ch11e6.cpp
#include <iostream>;
#include "stonewt.h";

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using STONEWT::Stonewt;
	double temp;
	Stonewt w[6] = {Stonewt(100.0), Stonewt(200.0), Stonewt(150.0)};

	// read in 3 more values from the user
	for(int i = 0; i < 3; i++)
	{
		cout << "Enter a weight (in pounds): ";
		if (!(cin >> temp) || temp < 0)
		{
			cout << "Error processing input. Program terminated." << endl;
			
			// clear input queue
			cin.clear();
			while( cin.get() != '\n');

			cout << "Press ENTER to exit.";
			cin.get();

			return 0;
		}

		w[i+3] = Stonewt(temp);

	}

	// clear inpute queue of a newline character
	cin.get();

	// compute smalles, largest, and the number of elements that are greater or equal to 11 stone
	Stonewt * small = &w[0];
	Stonewt * large = &w[0];
	int count = 0;
	Stonewt check = Stonewt(11, 0.0);
	for (int i = 1; i < 6; i++)
	{
		if (w[i] < *small)
			small = &w[i];
		if (w[i] > *large)
			large = &w[i];
		if (w[i] >= check)
			count++;
	}

	(*small).toStonePounds();
	(*large).toStonePounds();
	cout << "Smallest Weight - " << *small << endl;
	cout << "Largest Weight - " << *large << endl;
	cout << "Number of Weights greater or equal to 11 stone: " << count << endl;


	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}