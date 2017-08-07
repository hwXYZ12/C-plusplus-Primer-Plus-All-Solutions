// plorg.h - ch10e7
#ifndef PLORG_H_
#define PLORG_H_

namespace PLORG
{
	static const int NAME_LENGTH = 19;
	static const int INITIAL_CI = 50;
	static const char DEFAULT_NAME[NAME_LENGTH+1] = "Plorga";

	class Plorg
	{
	private:
		char name[NAME_LENGTH+1];
		int ci;
	public:
		Plorg(const char * who=DEFAULT_NAME);

		// changes the contentment index (ci) to cindex
		void setCI(int cindex);

		// reports plorg ci and name
		void show() const;
	};
}


#endif