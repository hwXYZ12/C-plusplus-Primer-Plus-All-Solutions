// chapter 10 exercise 5 - ch10e5.cpp
#include <iostream>;
#include "stack.h";

void removeCustomer(const Item & c)
{
	using std::cout;
	using std::endl;

	cout << "Customer removed from stack." << endl
		 << "Customer: " << c.fullname << endl
		 << "Payment: " << c.payment << endl;
}

void addCustomer(const Item & c)
{
	using std::cout;
	using std::endl;

	cout << "Customer added to the stack." << endl
		 << "Customer: " << c.fullname << endl
		 << "Payment: " << c.payment << endl;
}

int main()
{

	using std::cout;
	using std::cin;
	using std::endl;
	using STACK::Stack;

	// create a stack object
	Stack s;

	// use some random customer data
	Customer c1, c2, c3, c4, c5, temp;
	strcpy_s(c1.fullname, 1000, "Mike Jones"); // hardcoded for a quick example
	strcpy_s(c2.fullname, 1000, "Herb Jones");
	strcpy_s(c3.fullname, 1000, "The Maaaan");
	strcpy_s(c4.fullname, 1000, "The Guy");
	strcpy_s(c5.fullname, 1000, "Superman");
	c1.payment = 5;
	c2.payment = 6;
	c3.payment = 2234;
	c4.payment = 3454;
	c5.payment = 4594;

	// add all customers to the stack in random order
	s.push(c1);
	addCustomer(c1);
	s.push(c3);
	addCustomer(c3);
	s.push(c4);
	addCustomer(c4);
	s.push(c2);
	addCustomer(c2);
	s.push(c5);
	addCustomer(c5);

	// pop all customers from the stack
	// and report the total payments thus far
	double total = 0;
	for (int i = 0; i < 5; i++) // hardcoded loop to make a quick example
	{
		s.pop(temp);
		total += temp.payment;
		removeCustomer(temp);
		cout << "Total: " << total << endl; 
	}

	

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}