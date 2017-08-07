// Cd.h - ch13e1
#ifndef CD_H_
#define CD_H_

namespace CD
{
	class CD
	{
	private:
		char performers[50];
		char label[20];
		int selections;		// number of selections
		double playtime;	// playing time in minutes

	public:
		CD(char * s1, char * s2, int n, double x);
		CD(const CD & d);
		CD();
		~CD();
		virtual void report() const;	// reports all CD data
		CD & operator=(const CD & d);
	};

}


#endif