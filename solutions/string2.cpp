// string2.cpp - ch12e2
#include "string2.h";
#include <iostream>;
#include <cstring>; // using a few C-style string functions
#include <cctype>;	// check upper / lower case characters

namespace STRING2
{

	// initialize static class member
	int String::num_strings = 0;
	
	// static function
	inline int String::HowMany()
	{
		return num_strings;
	}


	String::String(const char * s) // construct String from a C string
	{
		len = std::strlen(s);		// set size
		str = new char[len + 1];	// allot storage
		strcpy_s(str, len+1, s);	// initialize pointer
		num_strings++;				// set object count
	}

	String::String()				// default constructor
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';				// default string
		num_strings++;
	}

	String::String(const String & s) // copy constructor
	{
		len = s.len;				// same length
		str = new char[len + 1];	// allot storage
		strcpy_s(str, len+1, s.str);	// copy string to new location
		num_strings++;				// set object count
	}


	String::~String()				// destructor
	{
		--num_strings;
		delete [] str;
	}

	// converts characters to lowercase
	void String::stringlow()
	{
		for(int i = 0; i < len; ++i)
			if ( isalpha(str[i]) && isupper(str[i]) )
				str[i] = tolower(str[i]);
	}

	// converts characters to uppercase
	void String::stringup()
	{
		for(int i = 0; i < len; ++i)
			if ( isalpha(str[i]) && islower(str[i]) )
				str[i] = toupper(str[i]);
	}

	// returns the number of occurrences of char h in this String
	int String::occurs(const char h) const
	{
		int count = 0;
		for(int i = 0; i < len; ++i)
			if (str[i] == h)
				++count;
		return count;
	}

	// overloaded operator methods

	// assign a String to a String
	String & String::operator=(const String & s)
	{
		// handle assigning to itself
		if (this == &s)
			return *this;
		delete [] str;
		len = s.len;					// same length
		str = new char[len + 1];		// allot storage
		strcpy_s(str, len+1, s.str);	// copy string to new location
		return *this;
	}

	// assign a C-style string to a String
	String & String::operator=(const char * s)
	{
		delete [] str;

		// strlen() will crash if given a nullptr argument so
		// we handle that here
		if (nullptr == s)
		{
			len = 0;				// no length
			str = new char[1];		// allot storage
			str[0] = '\0';			// null termiate the empty string
			return *this;
		}
		len = std::strlen(s);		// same length
		str = new char[len + 1];	// allot storage
		strcpy_s(str, len+1, s);	// copy string to new location
		return *this;
	}

	// read-write character access for non-const String
	char & String::operator[] (int i)
	{
		return str[i];
	}

	// read-only character access for const String
	const char & String::operator[] (int i) const
	{
		return str[i];
	}

	// overloaded operator friends
	bool operator<(const String & st1, const String & st2)
	{
		return (std::strcmp(st1.str, st2.str) < 0);
	}
	bool operator>(const String & st1, const String & st2)
	{
		return st2 < st1;
	}
	bool operator==(const String & st1, const String & st2)
	{
		return (std::strcmp(st1.str, st2.str) == 0);
	}

	// concatenate 2 String objects
	String operator+(const String & st1, const String & st2)
	{	
		String s;
		int len1 = std::strlen(st1.str);
		int len2 = std::strlen(st2.str);
		s.len = len1 + len2;						// summed length
		s.str = new char[s.len + 1];				// allot storage
		// manually copy st1 & st2 to s.str
		for(int i = 0; i < len1; ++i)
			s.str[i] = st1.str[i];
		for(int i=0; i<len2; ++i)
			s.str[i+len1] = st2.str[i];
		// null terminate the string
		s.str[s.len] = '\0';
		return s;
	}

	// String output
	ostream & operator<<(ostream & os, const String & st)
	{
		os << st.str;
		return os;
	}

	// quick & dirty String input
	istream & operator>>(istream & is, String & st)
	{
		char temp[String::CINLIM];
		is.get(temp, String::CINLIM);
		if (is)
			st = temp;
		while (is && is.get() != '\n')
			continue;
		return is;
	}

}