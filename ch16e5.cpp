// ch16e5 - chapter 16 exercise 5
#include <iostream>;
#include <algorithm>;
#include <string>;

// sorts, removes duplicates, and returns a value
// equal to the number of elements in the reduced
// array
template <class T>
int reduce(T ar[], int n)
{
	std::sort(&ar[0], &ar[n]);
	T * x = std::unique(&ar[0], &ar[n]);
	return x - &ar[0];
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	// test template using long values
	long nums[12] = {3, 4, 10, 4, 3, 14, 1, 17, 2, 17, 2, 3};

	cout << "Testing our reduce function on the following array: " << endl;
	for(int i=0;i<12;++i)
		cout << nums[i] << " ";


	int x=reduce(nums, 12);
	cout << endl
		 << "After reduce() is used on our array we have: "
		 << endl;
	for(int i=0;i<x;++i)
		cout << nums[i] << " ";
	cout << endl;
	
	// test template using string objects
	string words[12] = {"cat", "hat", "dog", "year", "gear", "hat", "cat", "dog", "hear", "year", "hat", "care"};

	cout << "Testing our reduce function on the following array: " << endl;
	for(int i=0;i<12;++i)
		cout << words[i] << " ";


	x=reduce(words, 12);
	cout << endl
		 << "After reduce() is used on our array we have: "
		 << endl;
	for(int i=0;i<x;++i)
		cout << words[i] << " ";
	cout << endl;


	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
