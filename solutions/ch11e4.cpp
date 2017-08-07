// chapter 11 exercise 4 - ch11e4.cpp
#include <iostream>;
#include "mytime4.h";

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using TIME::Time;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;
	
	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;		// operator+()
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;			// member operator*()
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10.0 * tosca << endl;

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}