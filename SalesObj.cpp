// sales.cpp - ch9e4
#include <iostream>;
#include "SalesObj.h";

namespace SALES
{


	/* copies the lesser of 4 or n items from the array ar
	   to the sales member and computes and stores the
	   average, minimum, and maximum values of the entered items;
	   remaining elements of sales, if any, set to 0.
	*/
	Sales::Sales(const double ar[], int n)
	{
		// store values
		for(int i=0; i < n; i++)
		{
			sales[i] = ar[i];
		}
		for(int i=n; i < QUARTERS; i++)
		{
			sales[i] = 0;
		}

		// compute the average, minimum, and maxiumum
		double minimum = sales[0];
		double maximum = sales[0];
		double total = sales[0];
		for(int i=1; i < QUARTERS; i++)
		{
			total += sales[i];
			if (sales[i] < minimum)
				minimum = sales[i];
			if (sales[i] > maximum)
				maximum = sales[i];
		}

		// set struct values
		average = total / QUARTERS;
		max = maximum;
		min = minimum;

	}

	/*  gathers sales for 4 quarters interactively, stores
		them in the sales member of s and computes and stores the
		average, minimum, and maximum values
	*/
	void Sales::setSales()
	{
		using std::cout;
		using std::cin;
		using std::endl;
		cout << "Please enter " << QUARTERS << " divisions of sales." << endl;
		for(int i=0; i < QUARTERS; i++)
		{
			cout << "Quarter " << (i+1) << ": ";
			cin >> sales[i];
			if (!cin)
			{
				cout << "ERROR - There has been an error processing your input." << endl
					 << "Default value set to 0." << endl;
				sales[i] = 0;
				// Clear input
				cin.clear();
				while(cin.get() != '\n');
			} else
				// Clear newline character
				cin.get();
		}

		// Once all 4 quarters of sales are retrieved from
		// the user we make a call to the constructor
		// and change the address of the calling object
		// to the address of the constructed object
		*this = Sales(sales, QUARTERS);

	}

	// display all information in Sales object
	void Sales::showSales() const
	{
		using std::cout;
		using std::endl;
		cout << "Sales for the year are as follows." << endl;
		for(int i=0; i < QUARTERS; i++)
			cout << "Quarter " << (i+1) << ": " << sales[i] << endl;
		cout << "Max: " << max << endl
			 << "Min: " << min << endl
			 << "Average: " << average << endl;
	
	}
}