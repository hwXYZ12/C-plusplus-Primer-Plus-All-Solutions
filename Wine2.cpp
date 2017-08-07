// Wine2.cpp - ch14e2
#include "Wine2.h";
#include <iostream>;
#include <iomanip>;

namespace WINE
{

	void Wine::getBottles()
	{
		using std::endl;
		using std::cout;
		using std::cin;
		cout << "Enter " << (const std::string &) *this << " data for "
			 << m_numOfYears << " year(s): " << endl;

		for(int i=0; i < m_numOfYears; ++i)
		{
			cout << "Enter year: ";
			cin >> ((PairArray &) *this).first()[i];
			if (!cin)
			{
				cout << "An error has occurred. Please press ENTER to exit.";

				cin.clear();
				while(cin.get() != '\n');
				cin.get();
				exit(1);
			}
			// clear input queue
			while (cin.get() != '\n');

			cout << "Enter bottles for that year: ";
			cin >> ((PairArray &) *this).second()[i];
			if (!cin)
			{
				cout << "An error has occurred. Please press ENTER to exit.";

				cin.clear();
				while(cin.get() != '\n');
				cin.get();
				exit(1);
			}
			// clear input queue
			while (cin.get() != '\n');

		} // for(int i=0; i < m_numOfYears; ++i)

	}
	
	static const int TABLE_CONST_1 = 10;
	static const int TABLE_CONST_2 = 15;

	void Wine::show()
	{
		using std::endl;
		using std::cout;
		using std::cout;
		using std::setw;
		cout << "Wine: " << (const std::string &) *this << endl
			 << setw(TABLE_CONST_1) << " " // shift table a bit to the right
			 << std::left << setw(TABLE_CONST_2) << "Year" 
			 << std::right << setw(TABLE_CONST_2) << "Bottles" << endl;
		for(int i = 0; i < m_numOfYears; ++i)
		{
			cout << setw(TABLE_CONST_1) << " " // shift table a bit to the right
				 << setw(TABLE_CONST_2) << std::left << ((PairArray &) *this).first()[i]
				 << setw(TABLE_CONST_2) << std::right << ((PairArray &) *this).second()[i] << endl;
		}

	}

}
