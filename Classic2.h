// Classic2.h - ch13e2
#ifndef CLASSIC2_H_
#define CLASSIC2_H_
#include "Cd2.h";

namespace CLASSIC
{
	class Classic : public CD::CD
	{
	private:
		char * primary;			// primary work on the CD
	public:
		Classic(char * s1, char * s2, char * s3, int n, double x);
		Classic(char * s1, const CD & cd);
		Classic(const Classic & c);
		Classic();
		~Classic();
		Classic & operator=(const Classic & c);
		void report() const;
	};

}


#endif