// chapter 5 exercise 4 - ch5e4.cpp
#include <iostream>
const long double DAPHNE_INITIAL = 100L, CLEO_INITIAL = 100L;
const long double DAPHNE_RATE = .1L, CLEO_RATE = .05L;

int main()
{
	using namespace std;
	long double daphne=DAPHNE_INITIAL, cleo=CLEO_INITIAL;
	long long year=0;
	// Compute how many years it will take Cleo to earn more money than Daphne if Daphne only earns
	// "simple interest" while Cleo earns compound interest.
	while (daphne >= cleo)
	{
		++year;
		daphne += DAPHNE_INITIAL*DAPHNE_RATE;
		cleo += cleo*CLEO_RATE;
	}
	cout << "Daphne and Cleo both invest $100 at year 0. Daphne earns interest at a rate of 10% but earns only";
	cout << " \"simple interest\" which means Daphne will earn only $10 each year. Cleo on the other hand will";
	cout << " earn compound interest at a rate of 5% each year. At year " << year << " Cleo will earn more money than Daphne." << endl;
	cout << "Year: " << year << endl;
	cout << "Daphne: " << daphne << endl;
	cout << "Cleo: " << cleo << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}