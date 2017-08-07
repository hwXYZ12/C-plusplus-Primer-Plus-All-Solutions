// chapter 7 exercise 3 - ch7e3.cpp
#include <iostream>
#include <cstring>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void funcA(box);
void funcB(box*);

int main()
{
	using namespace std;

	cout << "Here is a box!" << endl;
	box b;
	strcpy_s(b.maker, "Herp the Derp");
	b.height = 10;
	b.volume = 1;
	b.length = 10;
	b.width = 10;
	funcA(b);
	cout << "...where the unit of each physical property is inches..." << endl;
	cout << "You may have noticed that this seems illogical!" << endl;
	cout << "Indeed it is and we will now fix this and display the correct volume." << endl;
	funcB(&b);
	cout << "Corrected!" << endl;
	funcA(b);

	
	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}

// Takes a box struct by value and displays its contents
void funcA(box b)
{
	using namespace std;
	cout << "This box's properties are as follows:\n";
	cout << "Maker: " << b.maker << endl;
	cout << "Height: " << b.height << endl;
	cout << "Length: " << b.length << endl;
	cout << "Width: " << b.width << endl;
	cout << "Volume: " << b.volume << endl;
}

// Takes a box struct by address and alters the volume to a calculated value
void funcB(box* b)
{
	using namespace std;
	b->volume = b->height * b->length * b->width;
}