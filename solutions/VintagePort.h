// VintagePort.h - ch13e4
#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_

#include <iostream>;
#include "Port.h";

namespace VINTAGEPORT
{
	class VintagePort : public PORT::Port
	{
	private:
		char * nickname;			// ie, "The Noble" or "Old Velvet", etc.
		int year;					// vintage year
	public:
		VintagePort();
		VintagePort(const char * br, const char * std, int b, const char * nn, int y);
		VintagePort(const VintagePort & vp);
		~VintagePort()		{ delete [] nickname; }
		VintagePort & operator=(const VintagePort & vp);
		void show() const;
		friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
	};
}





#endif // !VINTAGEPORT_H_
