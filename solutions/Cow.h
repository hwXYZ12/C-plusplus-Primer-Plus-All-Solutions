// Cow.h - ch12e1
#ifndef COW_H_
#define COW_H_
#include <iostream>;

namespace COW
{

	// class constants
	static const int NAME_LENGTH = 20;
	static const int DEFAULT_HOBBY_LENGTH = 20;
	static const char DEFAULT_NAME[NAME_LENGTH+1] = "GOATCOW"; // +1 to account for the null character
	static const double DEFAULT_WEIGHT = 100.0;

	class Cow
	{
	private:
		char m_name[NAME_LENGTH+1]; // +1 to account for null character
		char * m_hobby;
		double m_weight;

	public:

		// default constructor
		Cow();

		// constructor
		Cow(const char * nm, const char * ho, double wt);

		// copy constructor
		Cow(const Cow & c);

		// destructor
		~Cow();

		// assignment operator overload
		Cow & operator=(const Cow & c);

		// other functionality
		void showCow() const;

	};
}

#endif