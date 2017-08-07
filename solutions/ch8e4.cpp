// chapter 8 exercise 4 - ch8e4.cpp
#include <iostream>
#include <cstring>
using namespace std;

// structs
struct stringy
{
	char * str; // points to a string
	int ct;		// length of a string (not counting '\0')
};

// allocates space for a copy of the char array, then sets the str member of 
// the stringy struct to point to that space and sets the ct variable of the 
// stringy struct to the length of the new c-style string
void set(stringy&, const char[]);

// prints the member string of a stringy object n times, where n=1 by default
void show(const stringy&, int n=1);

// prints a given string n number of times, where n=1 by default
void show(const char *, int n=1);


int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);

	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	// deletes the dynamic space
	// allocated by set()
	delete [] beany.str;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// allocates space for a copy of the char array, then sets the str member of 
// the stringy struct to point to that space and sets the ct variable of the 
// stringy struct to the length of the new c-style string
void set(stringy& s, const char arr[])
{
	// allocates just enough dynamic space to copy the given string
	int len = strlen(arr)+1; // need 1 more byte for the null terminating character
	char* p = new char[len];

	strcpy_s(p, len*sizeof(char), arr);
	

	// set stringy members
	s.ct = len;
	s.str = p;

}

// prints the member string of a stringy object n times, where n=1 by default
void show(const stringy& s, int n)
{
	if (n<=0)
		n=1;

	for(int i=0; i < n; i++)
	{
		cout << s.str << endl;
	}
}

// prints a given string n number of times, where n=1 by default
void show(const char * s, int n)
{
	if (n<=0)
		n=1;

	for(int i=0; i < n; i++)
	{
		cout << s << endl;
	}
}