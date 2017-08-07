// VintagePort.cpp - ch13e4
#include "VintagePort.h";
#include <iostream>;

namespace VINTAGEPORT
{
	// default constructor
	// Note that nickname is set to nullptr instead of a
	// default value!!!
	// Note also that year is set to -1, which is an indication of
	// a nonsensical value which one would hopefully infer to be a 
	// placeholder
	VintagePort::VintagePort()
		: Port()
	{
		nickname = nullptr;
		year = -1;
	}

	VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y)
		: Port(br, st, b)
	{
		nickname = new char[strlen(nn) + 1];
		strcpy_s(nickname, strlen(nn) + 1, nn);
		year = y;
	}

	VintagePort::VintagePort(const VintagePort & vp)
		: Port(vp)
	{
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
		year = vp.year;
	}

	VintagePort & VintagePort::operator=(const VintagePort & vp)
	{
		if (&vp == this)
			return *this;
		Port::operator=(vp);
		delete [] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
		year = vp.year;
		return *this;
	}

	void VintagePort::show() const
	{
		using std::cout;
		using std::endl;
		Port::show();
		cout << "Nickname: " << nickname << endl
			 << "Year: " << year << endl;
	}


	std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
	{
		operator<<(os, (const PORT::Port &) vp);
		os << ", " << vp.nickname << ", " << vp.year;
		return os;
	}

}



		