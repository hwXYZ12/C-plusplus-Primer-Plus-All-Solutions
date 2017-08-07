// permute.cpp
// permutes a string and prints the results to a txt file
#include <iostream>;
#include <fstream>;
#include <string>;
#include <algorithm>;

int main ()
{
	using namespace std;
	string test = "wpolenz";

	// create an out stream & open it
	ofstream fout;
	fout.open("herpthederp.txt");

	// sort 'test'
	sort(test.begin(), test.end());

	// print all of the permutations of 'test'
	while ( next_permutation(test.begin(), test.end()) )
	{
		fout << test << endl;
	}

	// close out stream
	fout.close();

	cin.get();
	cout << "Press ENTER to exit.";
	
}