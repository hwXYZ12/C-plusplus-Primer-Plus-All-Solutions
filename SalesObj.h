// SalesObj.h - ch10e4
#ifndef SALESOBJ_H_
#define SALESOBJ_H_

namespace SALES
{
	
	static const int QUARTERS = 4;

	// default null array of sales
	static const double NO_SALES[QUARTERS] = {0};

	class Sales
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;

	public:

	/* copies the lesser of 4 or n items from the array ar
	   to the sales member and computes and stores the
	   average, minimum, and maximum values of the entered items;
	   remaining elements of sales, if any, set to 0.
	*/
	Sales(const double ar[] = NO_SALES, int n = QUARTERS);

	/* gathers sales for 4 quarters interactively, stores
	   them in the sales member and computes and stores the
	   average, minimum, and maximum values
	*/
	void setSales();

	// display all sales information
	void showSales() const;

	};
}

#endif