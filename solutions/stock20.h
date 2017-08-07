// stock20.h - ch12e3
#ifndef STOCK20_H_
#define STOCK20_H_
#include <iostream>;
using std::ostream;
using std::istream;

namespace STOCK20
{
	static const char * DEFAULT_COMPANY_NAME = "no name";
	static const int DEFAULT_COMPANY_NAME_LENGTH = strlen(DEFAULT_COMPANY_NAME);

	class Stock
	{
	private:
		char * company;
		int shares;
		double share_val;
		double total_val;
		void set_tot()	{ total_val = shares * share_val; }

	public:
		Stock();		// default constructor
		Stock(const char * co, long n = 0, double pr = 0.0); // constructor
		Stock(const Stock & s); // copy constructor
		~Stock();		// destructor
		Stock & operator=(const Stock & s); // overloaded operator "="
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		const Stock & topval(const Stock & s) const;
		// overloaded operator << friend function
		friend ostream & operator<<(ostream & os, const Stock & s);
	};
}

#endif