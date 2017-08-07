// chapter 11 exercise 7 - ch11e7.cpp
#include <iostream>;
#include "complex0.h";

int main()
{
	using COMPLEX0::complex;
	using std::cout;
	using std::endl;
	using std::cin;
	complex a(3.0, 4.0);		// initialize to (3, 4i)
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n'
			 << "complex conjugate is " << ~c << '\n'
			 << "a is " << a << '\n'
			 << "a + c is " << a + c << '\n'
			 << "a - c is " << a - c << '\n'
			 << "a * c is " << a * c << '\n'
			 << "2 * c is " << 2 * c << '\n'
			 << "Enter a complex number (q to quit):\n";
	}

	// clear input queue
	cin.clear();
	while (cin.get() != '\n');

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}