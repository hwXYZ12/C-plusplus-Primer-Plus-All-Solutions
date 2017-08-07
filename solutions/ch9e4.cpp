// chapter 9 exercise 4 - ch9e4.cpp
#include <iostream>;
#include "sales.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace SALES;

	// create 2 sales objects
	Sales s1, s2;

	// create a double array to represent the
	// sales of a particular year
	double someData[QUARTERS] = {10, 200, 4, 2};

	// fill s1 with data (although only partially)
	setSales(s1, someData, 3);

	// fill s2 with data given by the user
	setSales(s2);
	
	// Display the data
	cout << "Now displaying sales from 2 different years." << endl;
	showSales(s1);
	showSales(s2);

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}