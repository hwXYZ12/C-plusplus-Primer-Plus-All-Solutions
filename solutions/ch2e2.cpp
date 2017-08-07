// chapter 1 exercise 2 - ch1e2.cpp
#include <iostream>
using namespace std;

int furlongsToYards(int furlongs)
{
	return furlongs * 220;
}


int main()
{
	int furlongs;
	cout << "Please enter a distance in furlongs: ______\b\b\b\b\b\b";
	cin >> furlongs;
	int yards = furlongsToYards(furlongs);
	cout << furlongs << " furlongs = " << yards << " yards.";
	cin.get();
	cin.get();
	return 0;
}