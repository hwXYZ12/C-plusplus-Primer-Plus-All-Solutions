// chapter 11 exercise 3 - ch11e3.cpp
#include <fstream>;
#include <cstdlib>;
#include <ctime>;
#include "Vector2.h";

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
	out.open("Random Walk(s).txt");

	int N;
	unsigned long high=0, low=0, total=0;
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
		
		cout << "Enter number of trials: ";
		if (!(cin >> N))
			break;

		// write target length and step size to file
		out << "Target Distance: " << target << ", Step Size: " << dstep << endl;

		// run the walk N times
		for(int i = 0; i < N; i++)
		{
			cout << endl;
			out << endl;
			// print trial #
			cout << "Trial #" << (i+1) << endl;
			// print trial # to file
			out << "Trial #" << (i+1) << endl;

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
			result.rect_mode();
			out << result << endl;
			result.polar_mode();
			out << " or\n" << result << endl;
			out << "Average outward distance per step = "
				 << result.magval()/steps << endl;

			// set high, low, and total steps
			// & set low for the first time
			if (0 == low)
				low = steps;
			if (steps > high)
				high = steps;
			if (steps < low)
				low = steps;
			total += steps;

			steps = 0;
			result.reset(0.0, 0.0); // back to rect mode
		}

		// whitespace
		cout << endl;
		out << endl;

		// report highest, lowest, and average number of steps
		unsigned long avg = total / N;
		cout << "Highest Number of Steps: " << high << endl
			 << "Lowest Number of Steps: " << low << endl
			 << "Average Number of Steps: " << avg << endl;

		// copy this output to the file
		out << "Highest Number of Steps: " << high << endl
			 << "Lowest Number of Steps: " << low << endl
			 << "Average Number of Steps: " << avg << endl;

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