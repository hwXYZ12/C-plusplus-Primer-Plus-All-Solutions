// chapter 10 exercise 1 - ch10e1.cpp
#include <iostream>;
#include "BankAccount.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using BANK_ACCOUNT::BankAccount;

	// create a bank account object
	BankAccount b = BankAccount("The Great White Buffalo", "913298793345982848", 42);

	// play with the object
	cout << "Here is our Bank Account object on display." << endl;
	b.display();
	cout << "We've deposited $1000 in our account." << endl;
	b.deposit(1000);
	b.display();
	cout << "We've withdrawn $1 from our account." << endl;
	b.withdraw(1);
	b.display();

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}