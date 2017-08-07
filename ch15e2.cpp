// chapter 15 exercise 2 - ch15e2.cpp
#include <iostream>;
#include <cmath>;
#include "exc_mean.h";
using namespace EXC_MEAN;
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	double x,y,z;

	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try							// start of try block
		{
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				 << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				 << " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		} // end of try block
		catch(bad_hmean & hm)		// start of catch block
		{
			cout << hm.what()
				 << "Try again.\n";
			continue;
		}
		catch (bad_gmean & gm)
		{
			cout << gm.what()
				 << "Sorry, you don't get to play any more.\n";
			break;
		} // end of catch block
	} // end of while(cin >> x >> y)

	cout << endl << "Press ENTER to exit.";
	cin.get();
	cin.get();
	cin.get();
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if(a<0||b<0)
		throw bad_gmean();
	return std::sqrt(a*b);
}
