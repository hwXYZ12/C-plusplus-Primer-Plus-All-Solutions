// ch16e4 - chapter 16 exercise 4
#include <iostream>;
#include <algorithm>;

// sorts, removes duplicates, and returns a value
// equal to the number of elements in the reduced
// array
int reduce(long ar[], int n)
{
	std::sort(&ar[0], &ar[n]);
	long * x = std::unique(&ar[0], &ar[n]);
	return x - &ar[0];
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

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


	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
