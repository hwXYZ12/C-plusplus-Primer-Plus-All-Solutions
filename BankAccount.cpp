// BankAccount.cpp - ch10e1
#include <string>;
#include <iostream>;
#include "BankAccount.h";

namespace BANK_ACCOUNT
{

// default constructor
BankAccount::BankAccount(std::string guy, std::string acctN, double start) : name(guy), acctNum(acctN), balance(start) {}

// copy constructor
/*BankAccount::BankAccount(BankAccount & acct)
{
	name = acct.name;
	acctNum = acct.acctNum;
	balance = acct.balance;
}
We'll use the default memberwise copy constructor */

// destructor - doesn't need to do anything
// BankAccount::~BankAccount() {}
// We don't even need to define it!

// overloaded assignment operator
// BankAccount & BankAccount::operator=(BankAccount &);
// Can use the default - won't define a new one

// default address operator, but we don't care about that
// BankAccount * BankAccount::operator&(BankAccount &);
// Again, default reference operator is just fine

// displays the contents of a BankAccount object
void BankAccount::display()
{
	using std::cout;
	using std::endl;
	cout << "Account Holder: " << name << endl
		 << "Account Number: " << acctNum << endl
		 << "Balance: " << balance << endl;
}

// deposits cash into this account
bool BankAccount::deposit(double amt)
{
	if (amt > 0)
	{
		balance += amt;
		return true;
	}
	return false;
}

// withdraws cash from this account
bool BankAccount::withdraw(double amt)
{
	if (amt > 0 && balance > amt)
	{
		balance -= amt;
		return true;
	}
	return false;
}

}