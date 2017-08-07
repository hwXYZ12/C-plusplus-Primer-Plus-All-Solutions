// chapter 18 exercise 3 - ch18e3.cpp
#include <iostream>;

template <class T, class... Args>
long double sum_values(T value, Args... args)
{
	return value + sum_values(args...);
}

template <class T>
long double sum_values(T value)
{
	return value;
}

int main()
{
	using namespace std;

	cout << "Some sums:" << endl;

	cout << sum_values('A', 'b', 10.29, 100, 612.1) << endl;
	cout << sum_values(100, 20, 30) << endl
		 << sum_values(10000.0, 2, 500, 4) << endl
		 << sum_values(1) << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}