// exc_mean.cpp - ch15e2
#include "exc_mean.h";

namespace EXC_MEAN
{
	bad_hmean::bad_hmean(double a, double b)
						 : logic_error("")
	{
		std::stringstream s;
		s << "hmean(" << a << ", " << b << "): "
			<< "invalid arguments: a = -b\n";
		logic_error::operator=(logic_error(s.str()));
	}
	
	bad_gmean::bad_gmean()
						: logic_error("gmean() arguments should be >= 0\n")
	{}
}
