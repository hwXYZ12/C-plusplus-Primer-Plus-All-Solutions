// chapter 13 exercise 4 - ch13e4.cpp

/*	dummy .cpp ... this exercise doesn't require a functioning
	program, rather only answers to two questions and the
	completed Port.h, Port.cpp, VintagePort.h, and VintagePort.cpp
	files.

	a)	See Port.cpp
	b)	Port(const char * br = "none", const char * st = "none", int b = 0);
		Port(const Port & p);
		Constructors are both redefined because you need a unique constructor
		for each class regardless of whether the class inherits from a base
		class or not unless you're dealing with an ABC. VintagePort is NOT
		an ABC so we ignore this special case.

		virtual ~Port() { delete [] brand; }
		Similarly, destructors are also unique to each class. In this case
		we use both a ~Port() and ~VintagePort() destructor because both
		classes use DMA specific to each class. If it was the case that
		DMA wasn't used then we would be able to use the default destructors
		and skip defining either of these functions.

		Port & operator=(const Port & p)
		Redefined because there are VintagePort private members that must be
		copied when using the = operator. If this wasn't defined for VintagePort
		then either the compiler would throw a compile time error or only copy
		the base Port members when somebody tries to use the = operator.

		Port & operator+=(int b);					
		Port & operator-=(int b);					
		Both of these functions are NOT redefined because they deal strictly with
		base class private members and therefore need not be redefined. In fact,
		you couldn't redefine them with this property since VintagePort would not
		have access to Port private members.

		int bottleCount() const
		NOT redefined for the same reason as given for operator+=(int b)
		and operator-=(int b)

		virtual void show() const
		Redefined since there are additional private members of 
		the VintagePort class that are displayed in the VintagePort class
		show() method but aren't displayed in the show() function of the Port class

		friend std::ostream & operator<<(std::ostream & os, const Port & p)
		Redefined for the same reason that 'virtual void show() const' above is
		redefined.

	c)	operator=() and operator<<() are not virtual for two reasons.
		operator<<() isn't virtual because a virtual function must be 
		a member function of a class while a friend function is strictly
		NOT a member of a class.
		operator=() on the other hand wouldn't make sense as a virtual
		function since the function signature would be different for
		each derived class. Note that this is also a reason why
		operator<<() wouldn't make sense as a virtual member.

	d)	See VintagePort.cpp

*/
