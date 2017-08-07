// chapter 10 exercise 2 - ch10e2.cpp
#include "Person.h";
#include <iostream>;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using PERSON::Person;

	// create some person objects and use their methods
	Person p1 = Person();
	Person p2 = Person("The Guy");
	Person p3 = Person("Professor", "Grim");
	p1.Show();
	cout << endl;
	p2.Show();
	cout << endl;
	p3.Show();
	cout << endl;
	p1.FormalShow();
	cout << endl;
	p2.FormalShow();
	cout << endl;
	p3.FormalShow();
	cout << endl;

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}