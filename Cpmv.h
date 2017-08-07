// Cpmv.h - ch18e2
#ifndef CPMV_H_
#define CPMV_H_
#include <string>;

namespace CPMV
{
	using std::string;

	class Cpmv
	{
	public:
		struct Info
		{
			string qcode;
			string zcode;
		};
	private:
		Info *pi;
	public:
		Cpmv();
		Cpmv(string q, string z);
		Cpmv(const Cpmv & cp);
		Cpmv(Cpmv && mv);
		~Cpmv();
		Cpmv & operator=(const Cpmv & cp);
		Cpmv & operator=(Cpmv && mv);
		Cpmv operator+(const Cpmv & obj) const;
		void display() const;
	}; // class Cpmv
}

#endif