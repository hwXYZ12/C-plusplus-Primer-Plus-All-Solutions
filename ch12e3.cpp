// chapter 12 exercise 3 - ch12e3.cpp
#include <iostream>;
#include "stock20.h";

static const int STKS = 4;
int main()
{
	using STOCK20::Stock;

	// create an array of initialized objects
	Stock stocks[STKS] = 
	{
		Stock("Nanosmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; ++st)
		std::cout << stocks[st];

	// set pointer to first element
	const Stock * top = &stocks[0];
	for(st = 1; st < STKS; ++st)
		top = &top->topval(stocks[st]);

	// now top points to the most valuable holding
	std::cout << "\nMost valuable holding:\n"
			  << *top;

	std::cout << "Press ENTER to exit.";
	std::cin.get();

	return 0;
}