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

	class base_bad_mean : public logic_error
	{
	private:
		double v1;
		double v2;
	public:
		base_bad_mean(double a=0, double b=0)
					  : v1(a), v2(b),
					    logic_error(nullptr)
		{}
	};

	class bad_hmean : public base_bad_mean
	{
	public:
		bad_hmean(double a=0, double b=0);
	};

	class bad_gmean : public base_bad_mean
	{
	public:
		bad_gmean(double a=0, double b=0);
	};
}


#endif