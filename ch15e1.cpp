// chapter 15 exercise 1 - ch15e1.cpp
#include <iostream>;
#include "tvfm.h";

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using TELEVISION::Remote;
	using TELEVISION::Tv;

	// test Tv and Remote functions
	Remote r(Remote::TV, Remote::Normal);
	Tv myTelevision(Tv::DVD, 150);

	r.volup(myTelevision);
	r.voldown(myTelevision);
	r.onoff(myTelevision);
	r.onoff(myTelevision);
	r.chanup(myTelevision);
	r.chandown(myTelevision);
	r.set_mode(myTelevision);
	r.set_input(myTelevision);
	r.set_chan(myTelevision, 100);
	r.showModusOperandi();

	myTelevision.onoff();
	myTelevision.onoff();
	if (myTelevision.ison())
		cout << "Our TV is on" << endl;
	else
		cout << "Our TV is off" << endl;
	myTelevision.volup();
	myTelevision.voldown();
	myTelevision.chanup();
	myTelevision.chandown();
	myTelevision.set_mode();
	myTelevision.set_input();
	myTelevision.toggleModus(r);
	myTelevision.settings();


	cout << endl << "Press ENTER to exit.";
	cin.get();
	return 0;
}