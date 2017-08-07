// chapter 12 exercise 4 - ch12e4.cpp
#include <iostream>;
#include "stack2.h";

int main()
{
	using STACK2::Stack;
	
	Stack<int> s1;		// default constructor
	Stack<int> s2(9);	// constructor with 9 elements

	// push a few elements into s2
	s2.push(2);
	s2.push(3);
	s2.push(1);

	Stack<int> s3(s2);	// copy constructor
	
	if (s1.isempty())
		std::cout << "s1 is Empty\n";
	else
		std::cout << "s1 is not Empty\n";

	if (s2.isempty())
		std::cout << "s2 is Empty\n";
	else
		std::cout << "s2 is not Empty\n";

	if (s3.isfull())
		std::cout << "s3 is full\n";
	else
		std::cout << "s3 is not full\n";

	for (int i = 3; i < 9; ++i)
		s3.push(i*i);
	std::cout << "s3 filled\n";

	if (s3.isfull())
		std::cout << "s3 is full\n";
	else
		std::cout << "s3 is not full\n";

	Stack<int> s4 = s3;	// overloaded = operator

	int x = 0;
	s4.pop(x);
	std::cout << "top of s4: " << x << "\n";

	std::cout << "Press ENTER to exit.";
	std::cin.get();

	return 0;
}