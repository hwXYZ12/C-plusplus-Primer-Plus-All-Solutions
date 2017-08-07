// chapter 10 exercise 4 - ch10e4.cpp
#include <iostream>;
#include "SalesObj.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using SALES::Sales;
	using SALES::QUARTERS;

	// create a double array to represent the
	// sales of a particular year
	double someData[QUARTERS] = {10, 200, 4, 2};

	// create 2 sales objects
	// the first will utilize the constructor
	// while the second will be constructed with defaults
	// and then filled in a later statement
	// with information given by the user
	Sales s1 = Sales(someData, 3), s2;

	// fill s2 with data given by the user
	s2.setSales();
	
	// Display the data
	cout << "Now displaying sales from 2 different years." << endl;
	s1.showSales();
	s2.showSales();

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}