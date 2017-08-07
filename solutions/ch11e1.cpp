// chapter 11 exercise 1 - ch11e1.cpp
#include <fstream>;
#include <cstdlib>;
#include <ctime>;
#include "Vector.h";

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ofstream;
	using VECTOR::Vector;
	srand(time(0));			// seed random number generator

	// declare an ofstream object 
	// and open a text file
	ofstream out;
	out.open("Random Walk.txt");

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target, dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		// write target length and step size to file
		out << "Target Distance: " << target << ", Step Size: " << dstep << endl;

		while (result.magval() < target )
		{
			// write current step location to file
			out << steps << ": " << result << endl;

			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			 << result.magval()/steps << endl;

		// write a copy of the concluding text
		// to file
		out << "After " << steps << " steps, the subject "
			"has the following location:\n";
		out << result << endl;
		result.polar_mode();
		out << " or\n" << result << endl;
		out << "Average outward distance per step = "
			 << result.magval()/steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	// clear input
	cin.clear();
	while (cin.get() != '\n');

	// close working text file
	out.close();

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}