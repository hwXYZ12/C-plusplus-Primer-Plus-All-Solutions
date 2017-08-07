// Port.h - ch12e4
#ifndef PORT_H_
#define PORT_H_
#include <iostream>;

namespace PORT
{
	class Port
	{
	private:
		enum {STYLE_LEN = 20};
		char * brand;
		char style[STYLE_LEN];	// ie, tawny, ruby, vintage
		int bottles;
	public:
		Port(const char * br = "none", const char * st = "none", int b = 0);
		Port(const Port & p);						// copy constructor
		virtual ~Port() { delete [] brand; }
		Port & operator=(const Port & p);
		Port & operator+=(int b);					// add b to bottles
		Port & operator-=(int b);					// subtract b from bottles, if available
		int bottleCount() const		{ return bottles;}
		virtual void show() const;
		friend std::ostream & operator<<(std::ostream & os, const Port & p);
	};

}



#endif