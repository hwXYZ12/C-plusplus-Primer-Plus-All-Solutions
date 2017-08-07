// stock20.cpp - ch12e3
#include "stock20.h";
#include <iostream>;

namespace STOCK20
{
	// constructors
	// default constructor
	Stock::Stock()
	{
		company = new char[DEFAULT_COMPANY_NAME_LENGTH + 1];		//allot storage
		// copy default string into company pointer
		strcpy_s(company, DEFAULT_COMPANY_NAME_LENGTH + 1, DEFAULT_COMPANY_NAME);
		shares = 0;
		share_val = 0.0;
		total_val = 0.0;
	}

	Stock::Stock(const char * co, long n, double pr)
	{
		// strlen() can't handle nullptr
		if (nullptr == co)
		{
			company = new char[1];  // allot storage
			company[0] = '\0';		// use empty string
		} else
		{
			int len = strlen(co);
			company = new char[len + 1];	// allot storage
			strcpy_s(company, len+1, co);	// copy c-style string co into company
		}
		
		if (n < 0)
		{
			std::cout << "Number of shares can't be negative; "
					  << company << " shares set to 0.\n";
			shares = 0;
		}
		else
			shares = n;
		share_val = pr;
		set_tot();
	}

	// copy constructor
	Stock::Stock(const Stock & s)
	{
		// strlen() can't handle nullptr
		if (nullptr == s.company)
		{
			company = new char[1];  // allot storage
			company[0] = '\0';		// use empty string
		} else
		{
			int len = strlen(s.company);
			company = new char[len + 1];			// allot storage
			strcpy_s(company, len+1, s.company);	// copy c-style string co into company
		}
		shares = s.shares;
		share_val = s.share_val;
		total_val = s.total_val;
	}

	// overloaded operator "="
	Stock & Stock::operator=(const Stock & s)
	{
		// free storage currently pointed to by company
		delete [] company;

		// strlen() can't handle nullptr
		if (nullptr == s.company)
		{
			company = new char[1];  // allot storage
			company[0] = '\0';		// use empty string
		} else
		{
			int len = strlen(s.company);
			company = new char[len + 1];			// allot storage
			strcpy_s(company, len+1, s.company);	// copy c-style string co into company
		}

		// memberwise copy primitive data
		shares = s.shares;
		share_val = s.share_val;
		total_val = s.total_val;
		return *this;
	}


	// destructor
	Stock::~Stock()
	{
		delete [] company;
	}

	// other methods
	void Stock::buy(long num, double price)
	{
		if (num < 0)
		{
			std::cout << "Number of shares purchased can't be negative. "
					  << "Transaction is aborted.\n";
		}
		else
		{
			shares += num;
			share_val = price;
			set_tot();
		}

	}

	void Stock::sell(long num, double price)
	{
		using std::cout;
		if (num < 0)
		{
			cout << "Number of shares sold can't be negative. "
				 << "Transaction is aborted.\n";
		} 
		else if (num < shares)
		{
			cout << "You can't sell more than you have! "
				 << "Transaction is aborted.\n";
		}
		else
		{
			shares -= num;
			share_val = price;
			set_tot();
		}
	}

	void Stock::update(double price)
	{
		share_val = price;
		set_tot();
	}

	// overloaded operator << friend function
	ostream & operator<<(ostream & os, const Stock & s)
	{
		using std::ios_base;
		// set format to #.###
		ios_base::fmtflags orig =
				os.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = os.precision(3);

		os << "Company: " << s.company
			 << "  Shares: " << s.shares << '\n';
		os << "  Share price: $" << s.share_val;
		// set format to #.##
		os.precision(2);
		os << "	Total Worth: $" << s.total_val << '\n';

		// restore original format
		os.setf(orig, ios_base::floatfield);
		os.precision(prec);
		return os;
	}

	const Stock & Stock::topval(const Stock & s) const
	{
		if (s.total_val > total_val)
			return s;
		else
			return *this;
	}

}