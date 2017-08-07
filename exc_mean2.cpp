// exc_mean.cpp - ch15e2
#include "exc_mean2.h";

namespace EXC_MEAN
{
	bad_hmean::bad_hmean(double a, double b)
						 : base_bad_mean(a,b)
	{
		std::stringstream s;
		s << "hmean(" << a << ", " << b << "): "
			<< "invalid arguments: a = -b\n";
		logic_error::operator=(logic_error(s.str()));
	}
	
	bad_gmean::bad_gmean(double a, double b)
						 : base_bad_mean(a,b)
	{
		std::stringstream s;
		s << "gmean() arguments should be >= 0\n";
		logic_error::operator=(logic_error(s.str()));
	}
}
