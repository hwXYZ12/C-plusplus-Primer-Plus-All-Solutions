// chapter 5 exercise 10 - ch5e10.cpp
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	cout << "Enter number of rows: ";
	int rows,n;
	cin >> rows;
	n = rows;
	string word = "";
	for(;rows>0;--rows)
	{
		for(int i=rows-1; i>0; --i)
			word+=".";
		for(int i=n-rows+1; i>0; --i)
			word+="*";
		cout << word << endl;
		word = "";
		
	}
	cout << "Press ENTER to exit." << endl;
	cin.get();
	cin.get();
	return 0;
}