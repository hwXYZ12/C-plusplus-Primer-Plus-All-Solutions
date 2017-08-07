// sales.cpp - ch9e4
#include <iostream>;
#include "sales.h";

namespace SALES
	{
	/*  copies the lesser of 4 or n items from the array ar
		to the sales member of s and computes and stores the
		average, minimum, and maximum values of the entered items;
		remaining elements of sales, if any, set to 0.
	*/
	void setSales(Sales & s, const double ar[], int n)
	{
		// store values
		for(int i=0; i < n; i++)
		{
			s.sales[i] = ar[i];
		}
		for(int i=n; i < QUARTERS; i++)
		{
			s.sales[i] = 0;
		}

		// compute the average, minimum, and maxiumum
		double min = s.sales[0];
		double max = s.sales[0];
		double total = s.sales[0];
		for(int i=1; i < QUARTERS; i++)
		{
			total += s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
			if (s.sales[i] > max)
				max = s.sales[i];
		}

		// set struct values
		s.average = total / QUARTERS;
		s.max = max;
		s.min = min;

	}

	/*  gathers sales for 4 quarters interactively, stores
		them in the sales member of s and computes and stores the
		average, minimum, and maximum values
	*/
	void setSales(Sales & s)
	{
		using std::cout;
		using std::cin;
		using std::endl;
		cout << "Please enter " << QUARTERS << " quarters of sales." << endl;
		for(int i=0; i < QUARTERS; i++)
		{
			cout << "Quarter " << (i+1) << ": ";
			cin >> s.sales[i];
			if (!cin)
			{
				cout << "ERROR - There has been an error processing your input." << endl
					 << "Default value set to 0." << endl;
				s.sales[i] = 0;
				// Clear input
				cin.clear();
				while(cin.get() != '\n');
			}
		}

		// Once all 4 quarters of sales are retrieved from
		// the user we make a call to the overloaded
		// setSales function to compute the min, max, and average sales
		setSales(s, s.sales, QUARTERS);

	}

	// display all information in structure s
	void showSales(const Sales & s)
	{
		using std::cout;
		using std::endl;
		cout << "Sales for the year are as follows." << endl;
		for(int i=0; i < QUARTERS; i++)
			cout << "Quarter " << (i+1) << ": " << s.sales[i] << endl;
		cout << "Max: " << s.max << endl
			 << "Min: " << s.min << endl
			 << "Average: " << s.average << endl;
	
	}
}