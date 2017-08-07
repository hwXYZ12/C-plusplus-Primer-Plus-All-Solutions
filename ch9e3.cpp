// chapter 9 exercise 3 - ch9e3.cpp
#include <iostream>;

// function prototype 
void strcount(std::string);

// allocate a buffer
static const int BUFFER_SIZE = 1000;
static char buffer[BUFFER_SIZE];

struct chaff 
{
	char dross[20];
	int slag;
};

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	
	cout << "Using placement new to create an array" << endl
		 << "of 2 struct objects and place them in a buffer..." << endl;

	// allocate space in the buffer for an
	// array of 2 chaff structures
	chaff * stuff = new (buffer) chaff[2];
	
	// assign data to the chaff structs
	strcpy_s(stuff[0].dross, 20, "Some shiet");
	stuff[0].slag = 20;
	strcpy_s(stuff[1].dross, 20, "Some more shiet");
	stuff[1].slag = 5000;

	// shows the assigned data as well as the size of the chaff struct
	cout << "Displaying data entered..." << endl;
	for(int i=0; i < 2; i++)
	{
		cout << "Dross: " << stuff[i].dross << endl
			 << "Slag: " << stuff[i].slag << endl;
	}
	cout << "sizeof(chaff): " << sizeof(chaff) << endl;

	cout << "Press ENTER to exit.";
	cin.get();

	return 0;
}