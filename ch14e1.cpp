// chapter 14 exercise 1 - ch14e1.cpp
#include <iostream>;
#include "Wine.h";

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using WINE::Wine;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);		// store label, years, give arrays yrs elements
	holding.getBottles();		// solicit input for year, bottle count
	holding.show();				// display object contents

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {48, 60, 72};
	// create new object, initalize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.show();
	cout << "Total bottles for " << more.label()	// use label() method
		 << ": " << more.sum() << endl;				// use sum() method
	
	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
