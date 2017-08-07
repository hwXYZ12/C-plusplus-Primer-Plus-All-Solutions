// chapter 16 exercise 7 - ch16e7.cpp
#include <iostream>;
#include <vector>;
#include <ctime>;
#include <algorithm>;

std::vector<int> lotto(int spots, int numSelected)
{
	using std::vector;
	using std::find;

	// initialize random number generator if it hasn't
	// already been initialized
	static bool randInit=false;
	if(!randInit)
	{
		std::srand(std::time(nullptr));
		randInit=true;
	}

	vector<int> ret;
	int temp=0;
	for(int i=0; i<numSelected; ++i)
	{
		temp=rand()%spots+1;
		// if we find the element in 'ret' then we
		// randomize another value and check until we
		// randomize a value that isn't contained in
		// 'ret'
		while(find(ret.begin(), ret.end(), temp)!=ret.end())
			temp=rand()%spots+1;
		ret.push_back(temp);
	}
	std::sort(ret.begin(), ret.end());
	return ret;
}


int main()
{
	using std::endl;
	using std::cout;
	using std::cin;
	using std::vector;

	vector<int> winners1;
	winners1 = lotto(51, 6);

	cout << "After rolling 6 numbers from 51 possible spots" << endl
		 << "we've determined the following winners: ";
	for(int x : winners1)
	{
		cout << x << " ";
	}
	cout << endl;
	
	vector<int> winners2;
	winners2 = lotto(10000, 1000);

	cout << "After rolling 10000 numbers from 1000 possible spots" << endl
		 << "we've determined the following winners: ";
	for(int x : winners2)
	{
		cout << x << " ";
	}
	cout << endl;


	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
