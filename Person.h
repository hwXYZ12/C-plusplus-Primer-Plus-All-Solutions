// Person.h - ch10e2
#ifndef PERSON_H_
#define PERSON_H_

#include <string>;

namespace PERSON
{
	using std::string;

	class Person
	{
	private:
		static const int LIMIT = 25;
		string lname;				// person's last name
		char fname[LIMIT];			// person's first name
	public:
		Person() {lname=""; fname[0] = '\0';} // #1
		Person(const string & ln, const char * fn = "Heyyou"); // #2
		void Show() const;				// firstname lastname format
		void FormalShow() const;		// lastname, firstname format
	};
}


#endif