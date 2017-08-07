// chapter 18 exercise 2 - ch18e2.cpp
#include <iostream>;
#include "Cpmv.h";
#include <utility>;

int main()
{
	using namespace std;
	using namespace CPMV;

	Cpmv cpmv1; // default constructor
	Cpmv cpmv2("some qcode", "some zcode"); // qcode & zcode constructor
	Cpmv cpmv3("another qcode", "another zcode"); // qcode & zcode constructor
	Cpmv cpmv4(cpmv2); // copy constructor
	Cpmv cpmv5(cpmv2 + cpmv3); // copy constructor and operator+
	cpmv1.~Cpmv(); // call destructor

	cpmv3 = cpmv3 + cpmv3; // move assignment and + operator
	cpmv2 = move(cpmv5); // move assignment operator, note that cpmv5 is
						 // useless now and ought to be destructed
	cpmv5.~Cpmv();
	
	// display each cpmv object
	cpmv2.display();
	cpmv3.display();
	cpmv4.display();

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}