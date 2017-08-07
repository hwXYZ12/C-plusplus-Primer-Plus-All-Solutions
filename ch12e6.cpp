// chapter 12 exercise 6 - ch12e6.cpp
#include <iostream>;
#include <cstdlib>;		// for rand() & srand()
#include <ctime>;		// for time()
#include "queue.h";
#include "customer.h";
const int MIN_PER_HR = 60;

bool newcustomer(double x);		// is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	using QUEUE::Queue;
	using CUSTOMER::Customer;
	// setting things up
	std::srand(std::time(0));		// random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n"
		 << "Enter maximum size of queue #1: ";
	int qs1;
	cin >> qs1;
	Queue<Customer> line1(qs1);		// line queue #1 holds up to qs1 people

	cout << "Enter maximum size of queue #2: ";
	int qs2;
	cin >> qs2;
	Queue<Customer> line2(qs2);		// line queue #2 holds up to qs2 people

	cout << "Enter the number of simulation hours: ";
	int hours;						// hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours;	// # of cycles

	cout << "Enter the average number of customers per hour: ";
	double perhour;					// average # of arrivals per hour
	cin >> perhour;
	double min_per_cust;			// average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Customer temp;					// new customer data
	long turnaways = 0;				// turned away by full queues
	long customers = 0;				// joined either queue
	long served = 0;				// served during the simulation
	long sum_line1 = 0;				// cumulative line length of queue #1
	long sum_line2 = 0;				// cumulative line length of queue #2
	int wait_time1 = 0;				// time until autoteller #1 is free
	int wait_time2 = 0;				// time until autoteller #2 is free
	long line_wait = 0;				// cumulative time in either line

	// running the simulation
	// note that this code can be a bit confusing since dequeue()
	// will bind 'temp' to the first customer in the queue
	for (int cycle = 0; cycle < cyclelimit; ++cycle)
	{
		if (newcustomer(min_per_cust))		// have newcomer
		{
			if (line1.isfull() && line2.isfull())
				++turnaways;
			else
			{
				++customers;
				temp.set(cycle);			// cycle = time of arrival

				// add newcomer to the shorter of line1 & line2
				if (line1.queuecount() < line2.queuecount())
					line1.enqueue(temp);			// add newcomer to line1
				else
					line2.enqueue(temp);			// add newcomer to line2
			}

		}

		// handle autoteller #1
		if (wait_time1 <= 0 && !line1.isempty())
		{
			// attend next customer on line1
			line1.dequeue(temp);				
			wait_time1 = temp.ptime();		// for wait_time1 minutes
			line_wait += cycle - temp.when();
			served++;
		}

		// handle autoteller #2
		if (wait_time2 <= 0 && !line2.isempty())
		{
			// attend next customer on line2
			line2.dequeue(temp);				
			wait_time2 = temp.ptime();		// for wait_time2 minutes
			line_wait += cycle - temp.when();
			served++;
		}

		// decrement wait time for both autotellers
		if (wait_time1 > 0)
			--wait_time1;
		if (wait_time2 > 0)
			--wait_time2;

		sum_line1 += line1.queuecount();
		sum_line2 += line2.queuecount();

	}

	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl
			 << "  customers served: " << served << endl
			 << "         turnaways: " << turnaways << endl
			 << "average size of queue 1: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line1 / cyclelimit << endl
			 << "average size of queue 2: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line2 / cyclelimit << endl
			 << " average wait time: "
			 << (double) line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";

	// clear input queue
	while (cin.get() != '\n');

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}

//	x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand () * x / RAND_MAX < 1);
}



