// chapter 5 exercise 3 - ch5e3.cpp
#include <iostream>

int main()
{
	using namespace std;
	long long sum=0;
	long long x;
	cout << "Please enter an integer: ";
	cin >> x;
	while (x!=0)
	{
		sum+=x;
		cout << "Your current sum is: " << sum << endl;
		cout << "Please enter another integer (enter 0 to exit): ";
		cin >> x;
	}
	return 0;
}