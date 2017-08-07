// string2.h - ch12e2
#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>;
#include <cctype>;
using std::ostream;
using std::istream;

namespace STRING2
{

	class String
	{
	private:
		char * str;		// pointer to string
		int len;		// length of string
		static int num_strings;	// number of objects
		static const int CINLIM = 80; // cin input limit

	public:

		// constructors and other methods
		String(const char * s); // constructor
		String();				// default constructor
		String(const String &); // copy constructor
		~String();				// destructor
		int length() const { return len; }
		void stringlow();		// converts characters to lowercase
		void stringup();		// converts characters to uppercase
		// returns the number of occurrences of char h in this String
		int occurs(const char h) const;

		// overloaded operator methods
		String & operator=(const String &);
		String & operator=(const char *);
		char & operator[] (int i);
		const char & operator[] (int i) const;

		// overloaded operator friends
		friend bool operator<(const String & st1, const String & st2);
		friend bool operator>(const String & st1, const String & st2);
		friend bool operator==(const String & st1, const String & st2);
		friend String operator+(const String & st1, const String & st2);
		friend ostream & operator<<(ostream & os, const String & st);
		friend istream & operator>>(istream & is, String & st);

		// static function
		static int HowMany();

	};
}

#endif