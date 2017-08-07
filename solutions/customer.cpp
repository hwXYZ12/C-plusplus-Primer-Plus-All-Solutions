// customer.cpp - ch12e5 & ch16e6
#include "customer.h";
#include <cstdlib>;		// for rand()

namespace CUSTOMER
{
	// when is the time at which the customer arrives
	// the arrival time is set to when and the processing
	// time set to a random value in the range 1 to 3
	void Customer::set(long when)
	{
		processtime = std::rand() % 3 + 1;
		arrive = when;
	}

}
