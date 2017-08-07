// complex0.h - ch11e7
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>;

namespace COMPLEX0
{
	class complex
	{
	private:
		double r;
		double im;
	public:

		//default constructor
		complex(double real = 0, double imaginary = 0) : r(real), im(imaginary) {}

		// destructor
		~complex() {}

		// operator overloading (inlined)
		complex operator+(const complex & t) const
		{return complex(r+t.r, im+t.im);}
		complex operator-(const complex & t) const
		{return complex(r-t.r, im-t.im);}
		complex operator*(const complex & t) const
		{return complex(r*t.r-im*t.im, r*t.im+im*t.r);}
		complex operator*(double mult) const
		{return complex(r*mult, im*mult);}
		complex operator~() const
		{return complex(r, -im);}
		friend complex operator*(double mult, complex & t)
		{return t * mult;}
		friend std::ostream & operator<<(std::ostream & os, const complex & t)
		{return os << "(" << t.r << ", " << t.im << "i)";}
		friend std::istream & operator>>(std::istream & is, complex & t)
		{
			std::cout << "real: ";
			is >> t.r;
			if (is)
			{
				std::cout << "imaginary: ";
				is >> t.im;
			}
			return is;
		}


	};
}

#endif