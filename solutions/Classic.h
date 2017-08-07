// Classic.h - ch13e1
#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "Cd.h";

namespace CLASSIC
{
	class Classic : public CD::CD
	{
	private:
		char primary[50];		// primary work on the CD
	public:
		Classic(char * s1, char * s2, char * s3, int n, double x);
		Classic(char * s1, const CD & cd);
		Classic(const Classic & c);
		Classic();
		~Classic();
		Classic & operator=(const Classic & c);
		void report() const;	// reports all CD Data & reports the primary classical piece
	};

}


#endif