// Wine.cpp - ch14e1
#include "Wine.h";
#include <iostream>;
#include <iomanip>;

namespace WINE
{

	void Wine::getBottles()
	{
		using std::endl;
		using std::cout;
		using std::cin;
		cout << "Enter " << m_name << " data for "
			 << m_numOfYears << " year(s): " << endl;

		for(int i=0; i < m_numOfYears; ++i)
		{
			cout << "Enter year: ";
			cin >> m_pairArrayInt.first()[i];
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
			cin >> m_pairArrayInt.second()[i];
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
		cout << "Wine: " << m_name << endl
			 << setw(TABLE_CONST_1) << " " // shift table a bit to the right
			 << std::left << setw(TABLE_CONST_2) << "Year" 
			 << std::right << setw(TABLE_CONST_2) << "Bottles" << endl;
		for(int i = 0; i < m_numOfYears; ++i)
		{
			cout << setw(TABLE_CONST_1) << " " // shift table a bit to the right
				 << setw(TABLE_CONST_2) << std::left << m_pairArrayInt.first()[i]
				 << setw(TABLE_CONST_2) << std::right << m_pairArrayInt.second()[i] << endl;
		}

	}

}
