// chapter 14 exercise 5 - ch14e5.cpp
#include <iostream>;
#include "emp.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace EMPLOYEES;

	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.showAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.showAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.showAll();

	highfink hf(ma, "Curly Kew");	// recruitment?
	hf.showAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.setAll();

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for(int i=0; i<4; ++i)
		tri[i]->showAll();

	cout << endl << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}


/* Why is no assignment operator defined?
		I suppose an assignment operator could be defined but
	I imagine that you'd want your employees to be unique...

	Why are showAll() and setAll() virtual?
		The only reason I know of to declare a method
	virtual is so that you can make use of "late binding"
	of pointers to base class objects. Thus, we want to be
	able to use a function that takes a base class pointer
	or reference and call the correct showAll() or setAll()
	function depending on the object type.

	Why is abstr_emp a virtual base class?
		We use abstr_emp to capture some essential data
	and functionality of our employee classes in general
	but abstr_emp itself doesn't have enough data and/or
	functionality to be a useful class in and of itself.

	Why does the highfink class have no data section?
		The highfink class derives from two base classes
	which, between the two of them, contain enough data
	for the functionality contained in the highfink. Thus,
	more data isn't required beyond the inherited data from
	the base classes.

	Why is only one version of operator<<() needed?
		I'm not sure. I know that the method is a friend
	although it would seem you'd want to overload the function
	for each derived class...

	What would happen if the end of the program were replaced
	with this code?
	abstr_emp tri[4] = {em, fi, hf, hf2};
	for(int i=0; i<4; ++i)
		tri[i].showAll();

		abstr_emp is a virtual base class which means
	it cannot be instantiated. Thus an array of abstr_emp
	objects is not allowed and a compiler error will be
	issued.
		
*/