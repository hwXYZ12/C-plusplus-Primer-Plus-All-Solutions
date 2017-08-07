// Port.cpp - ch13e4
#include "Port.h";

namespace PORT
{
	Port::Port(const char * br, const char * st, int b)
	{
		brand = new char[strlen(br) + 1];
		strcpy_s(brand, strlen(br) + 1, br);
		strcpy_s(style, STYLE_LEN + 1, st);
		bottles = b;
	}

	Port::Port(const Port & p)
	{
		brand = new char[strlen(p.brand) + 1];
		strcpy_s(brand, strlen(p.brand) + 1, p.brand);
		strcpy_s(style, STYLE_LEN + 1, p.style);
		bottles = p.bottles;
	}

	Port & Port::operator=(const Port & p)
	{
		if (&p == this)
			return *this;
		delete [] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy_s(brand, strlen(p.brand) + 1, p.brand);
		strcpy_s(style, STYLE_LEN + 1, p.style);
		bottles = p.bottles;
		return *this;
	}

	Port & Port::operator+=(int b)
	{
		bottles += b;
		return *this;
	}

	// note that there is no warning in the case that the
	// user cannot subtract the given number of bottles
	Port & Port::operator-=(int b)
	{
		if (bottles >= b)
			bottles -= b;
		return *this;
	}

	void Port::show() const
	{
		std::cout << "Brand: " << brand << std::endl
				  << "Kind: " << style << std::endl
				  << "Bottles: " << bottles << std::endl;
	}

	std::ostream & operator<<(std::ostream & os, const Port & p)
	{
		os << p.brand << ", " << p.style << ", " << p.bottles;
		return os;
	}

}

	