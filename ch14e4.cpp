// chapter 14 exercise 4 - ch14e4.cpp
#include <iostream>;
#include "people.h";

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using namespace PEOPLE;

	Person p;

	cout << "A default person... " << endl;
	p.show();

	cout << "Another person... " << endl;
	Person smitty("Smitty", "McWeinberger");
	smitty.show();

	PokerPlayer pp(smitty);
	cout << "Smitty is also a PokerPlayer and will"
		    " draw a card for us: " << pp.draw() << endl;

	cout << "Reprint smittys name for the hell of it... " << endl;
	pp.show();

	GunSlinger gs("Bob", "Bigguns", 1.0, 50);
	cout << "Bob is a GunSlinger..." << endl;
	gs.show();
	cout << "His draw time is: " << gs.draw() << endl;

	BadDude bd(gs);
	cout << "Bob is both a GunSlinger AND a PokerPlayer "
			"therefore Bob is a BadDude" << endl;
	bd.show();
	cout << "Bob draws a card: " << bd.cDraw() << endl
		 << "Bobs gun draw time is: " << bd.gDraw() << endl;
	
	cout << endl << "Press ENTER to exit.";
	cin.get();
	return 0;
}
