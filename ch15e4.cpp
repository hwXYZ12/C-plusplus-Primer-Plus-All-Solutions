// chapter 15 exeric1se 4 - ch15e4.cpp
#include <iostream>;
#include "sales2.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace SALES;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 14,
		28, 29, 33, 29, 32, 35
	};
	
	Sales sales1(2011, vals1, 12);
	labeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.getYear() << endl;
		cout << "Label = " << sales2.getLabel() << endl;
		for (i=0;i<=12; ++i)
		{
			cout << sales2[i] << ' ';
			if(i%6==5)
				cout << endl;
		}
		cout << "End of try block 1.\n";

	}
	catch(Sales::bad_index & bad)
	{
		cout << bad.what();
		if (typeid(bad) == typeid(labeledSales::nbad_index))
			cout << "Company: " << ((labeledSales::nbad_index &) bad).label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch(Sales::bad_index & bad)
	{
		cout << bad.what();
		if (typeid(bad) == typeid(labeledSales::nbad_index))
			cout << "Company: " << ((labeledSales::nbad_index &) bad).label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}


	cout << endl << "Press ENTER to exit.";
	cin.get();
	return 0;
}
