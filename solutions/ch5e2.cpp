// chapter 5 exercise 2 - ch5e2.cpp
#include <iostream>
#include <array>
const int ArSize = 100;

int main()
{
	using namespace std;
	array<long double, ArSize> factorials; 
	factorials[0] = factorials[1] = 1.0L;
	for(int i=2; i<ArSize; i++)
		factorials[i] = i * factorials[i-1];
	for(int i=0; i<ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	return 0;
}