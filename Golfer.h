// Golfer.h - ch10e3
#ifndef GOLFER_H_
#define GOLFER_H_

namespace GOLFER
{
	class Golfer
	{		
	private:
		static const int Len = 40;
		char fullname[Len];
		int handicap;
	public:
		
		/* non-interactive version:
		   function sets golf object to provided name and handicap
		   using values passed as arguments to the function
		*/
		Golfer(const char * = "", int hc = 0);
		
		/* interactive version:
		   function solicits name and handicap from user
		   and sets the data accordingly
		*/
		int setGolfer();

		// function resets handicap to new values
		void setHandicap(int hc=0);

		// function displays contents of golf structure
		void showGolf() const;
	};

}

#endif