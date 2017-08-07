// chapter 11 exercise 5 - ch11e5.cpp
#include <iostream>;
#include "stonewt.h";

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using STONEWT::Stonewt;
	Stonewt w1(220);
	Stonewt w2(10, 35);
	Stonewt temp;
	
	cout << "Playing with weights:\n";
	cout << "Weight 1 - " << w1 << endl;
	cout << "Weight 2 - " << w2 << endl;

	// change state
	w1.toStonePounds();
	cout << "Weight 1 - " << w1 << endl;
	w2.toPounds();
	cout << "Weight 2 - " << w2 << endl;

	// shown in pounds
	temp = w1 + w2;		// operator+()
	cout << "Weight 1 + Weight 2 -> " << temp << endl;
	temp = w1 - w2;
	cout << "Weight 1 - Weight 2 -> " << temp << endl;
	temp = w1 * w2;
	cout << "Weight 1 * Weight 2 -> " << temp << endl;

	// shown in stone, pounds form
	temp = w1 + w2;		// operator+()
	temp.toStonePounds();
	cout << "Weight 1 + Weight 2 -> " << temp << endl;
	temp = w1 - w2;
	temp.toStonePounds();
	cout << "Weight 1 - Weight 2 -> " << temp << endl;
	temp = w1 * w2;
	temp.toStonePounds();
	cout << "Weight 1 * Weight 2 -> " << temp << endl;


	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}