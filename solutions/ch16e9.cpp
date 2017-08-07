// chapter 16 exercise 9 - ch16e9.cpp
#include <iostream>;
#include <vector>;
#include <ctime>;
#include <list>;
#include <algorithm>;
static const int NUM = 1000000;

int main()
{
	using std::endl;
	using std::cout;
	using std::cin;
	using std::vector;
	using std::list;
	using std::time;

	// seed pseudo-random number generator
	std::srand(time(nullptr));

	vector<int> vi0(NUM);
	for(int i=0;i<NUM;++i)
	{
		vi0.push_back(rand()%NUM+1);
	}

	vector<int> vi(vi0);
	list<int> li(NUM);
	for(int x:vi0)
		li.push_back(x);

	// time sorting vi using STL sort()
	// and time sorting li using list sort()
	clock_t startTime;
	double stlSortTime, listSortTime, combinedSortTime;

	startTime = clock();
	std::sort(vi.begin(), vi.end());
	stlSortTime = (double) (clock() - startTime) / CLOCKS_PER_SEC;

	startTime = clock();
	li.sort();
	listSortTime = (double) (clock() - startTime) / CLOCKS_PER_SEC;

	li.clear();
	for(int x:vi0)
		li.push_back(x);

	// time copying li to vi, sorting vi, and copying
	// the result back to li
	vi.clear();
	startTime = clock();
	for(int x:li)
		vi.push_back(x);
	sort(vi.begin(), vi.end());
	for(int x:vi)
	{
		li.pop_front();
		li.push_back(x);
	}
	combinedSortTime = (double) (clock() - startTime) / CLOCKS_PER_SEC;

	cout << "After running our test we've found that..." << endl
		 << "Sorting a vector<int> object with " << NUM << endl << "elements using STL-sort yields a time of: " << stlSortTime << endl
		 << "Sorting a list<int> object with " << NUM << endl << "elements using list-sort yields a time of: " << listSortTime << endl
		 << "Copying a list<int> object to a vector<int> object," << endl
		 << "sorting the vector<int> object, and copying the sorted" << endl
		 << "values back from vector<int> to list<int> using " << NUM << endl << "elements yields a time of: " << combinedSortTime << endl;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}