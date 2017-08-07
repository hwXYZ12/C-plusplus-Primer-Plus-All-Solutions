// BankAccount.h - ch10e1
#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_

#include <string>;

namespace BANK_ACCOUNT
{

class BankAccount
{
private:
	std::string name;			// account holder's name
	std::string acctNum;		// account number
	double balance;				// account balance
public:
	 // default constructor
	BankAccount(std::string="none", std::string="none", double=0);

	// copy constructor
	//BankAccount(BankAccount &); 

	 // destructor
	//virtual ~BankAccount();

	 // overloaded assignment operator
	//BankAccount & operator=(BankAccount &);

	// default address operator, but we don't care about that
	//BankAccount * operator&(BankAccount &);

	// displays the contents of a BankAccount object
	void display();

	// deposits cash into this account
	bool deposit(double);

	// withdraws cash from this account
	bool withdraw(double);
};

}

#endif