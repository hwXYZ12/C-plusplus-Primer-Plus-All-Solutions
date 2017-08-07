// Cd2.h - ch13e2
#ifndef CD2_H_
#define CD2_H_

namespace CD
{
	class CD
	{
	private:
		char * performers;
		char * label;
		int selections;		// number of selections
		double playtime;	// playing time in minutes

	public:
		CD(char * s1, char * s2, int n, double x);
		CD(const CD & d);
		CD();
		virtual ~CD();
		virtual void report() const;	// reports all CD data
		CD & operator=(const CD & d);
	};

}


#endif