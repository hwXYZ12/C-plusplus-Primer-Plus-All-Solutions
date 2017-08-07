// chapter 4 exercise 10 - ch4e10.cpp
#include <iostream>

int main()
{
	using namespace std;
	double t[3];
	cout << "Please record your 3 best times achieved while running the 40 yard dash.\nFirst run: ";
	cin >> t[0];
	cout << "Second run: ";
	cin >> t[1];
	cout << "Third run: ";
	cin >> t[2];
	double avg = (t[0] + t[1] + t[2])/3.0;
	cout << "Your average time is: " << avg << " s" << endl;
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}