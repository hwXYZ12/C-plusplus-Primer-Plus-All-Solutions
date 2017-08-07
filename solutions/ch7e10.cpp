// chapter 7 exercise 10 - ch7e10.cpp
#include <iostream>

// add function, returns the sum of two doubles
double add(double, double);

// subtract function, returns the difference between two doubles
double subtract(double, double);

// multiply function, returns the product of two doubles
double multiply(double, double);

// calculate function uses a pointer to a function in order to perform an
// abstract calculation on two doubles and return the result
double calculate(double, double, double (*f)(double, double));


int main()
{
	
	using namespace std;

	/* We'll run a loop to prompt the user for
	   pairs of doubles. Once we've obtained a pair
	   then we will run the calculate() method using
	   some preconceived functions. We'll print the
	   results and repeat the process. The user ought
	   to enter q or some other invalid input in
	   order to terminate input.
	*/ 
	double temp, x, y;
	while(true)
	{
		cout << "Please enter a pair of numbers to perform calculations on (q to quit).\nNumber 1: ";
		cin >> temp;
		if (!cin)
		{
			// user has satisfied the exit condition

			// clear input queue & revert checkbit
			cin.clear();
			while(cin.get() != '\n');

			break;
		}
		x = temp;
		cout << "Number 2: ";
		cin >> temp;
		if (!cin)
		{
			// user has satisfied the exit condition

			// clear input queue & revert checkbit
			cin.clear();
			while(cin.get() != '\n');

			break;
		}
		y = temp; 

		// we've got both numbers, now we perform the calculations
		cout << "Some calculations on the given numbers: " << endl;
		double (*funcs[])(double, double) = {add, subtract, multiply};
		const char* names[] = {"+", "-", "*"};
		for(int i=0; i < 3; i++)
		{
			cout << x << " " << names[i] << " " << y << " = " << calculate(x,y, funcs[i]) << endl;
		}

	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}


// add function, returns the sum of two doubles
double add(double x, double y)
{
	return x+y;
}

// subtract function, returns the difference between two doubles
double subtract(double x, double y)
{
	return x-y;
}

// multiply function, returns the product of two doubles
double multiply(double x, double y)
{
	return x*y;
}

// calculate function uses a pointer to a function in order to perform an
// abstract calculation on two doubles and return the result
double calculate(double x, double y, double (*f)(double, double))
{
	return f(x,y);
}