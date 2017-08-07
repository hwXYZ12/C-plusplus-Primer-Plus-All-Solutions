// exc_mean.h - ch15e2
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_

#include <iostream>;
#include <stdexcept>;
#include <string>;
#include <sstream>;

namespace EXC_MEAN
{
	using std::logic_error;
	using std::string;
	using std::stringstream;

	class bad_hmean : public logic_error
	{
	public:
		bad_hmean(double a=0, double b=0);
	};

	class bad_gmean : public logic_error
	{
	public:
		bad_gmean();
	};
}


#endif