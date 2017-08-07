// customer.h - ch12e5 & ch16e6
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

namespace CUSTOMER
{
	class Customer
	{
	private:
		long arrive;		// arrival time for customer
		int processtime;	// processing time for customer
	public:
		Customer()			{ arrive = processtime = 0; }
		void set(long when);
		long when() const	{ return arrive; }
		int ptime() const	{ return processtime; }
	};
}


#endif