// dma.cpp - ch13e3
#include "dma.h";
#include <iostream>;

// Base class using DMA
namespace DMA
{
	// Essentially a replacement for a constructor....
	void DMAABC::setLabelAndRating(const char * l, int r)
	{
		label = new char[strlen(l) + 1];
		strcpy_s(label, strlen(l) + 1, l);
		rating = r;
	}

	baseDMA::baseDMA(const char * l, int r)
	{
		DMAABC::setLabelAndRating(l, r);
	}

	baseDMA::baseDMA(const baseDMA & rs)
	{
		DMAABC::setLabelAndRating(rs.getLabel(), rs.getRating());
	}

	// using dma so destructor is necessary
	baseDMA::~baseDMA()
	{
		DMAABC::freeLabel();
	}

	// overloaded '=' operator
	baseDMA & baseDMA::operator=(const baseDMA & rs)
	{
		if (this == &rs)
			return *this;

		DMAABC::freeLabel();
		DMAABC::setLabelAndRating(rs.getLabel(), rs.getRating());
		return *this;
	}

	// overloaded '>>' operator
	std::ostream & operator<<(std::ostream & os,
							  const baseDMA & rs)
	{
		os << "Label: " << rs.getLabel() << std::endl
		   << "Rating: " << rs.getRating() << std::endl;
		return os;
	}
	
	// these functions are also not even useful.......
	void baseDMA::view() const
	{
		std::cout << *this;
	}

	// lacksDMA constructors
	lacksDMA::lacksDMA(const char * c, const char * l,
					   int r) : baseDMA(l, r)
	{
		strcpy_s(color, COL_LEN - 1, c);
		color[COL_LEN - 1] = '\0';
	}

	lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
		: baseDMA(rs)
	{
		strcpy_s(color, COL_LEN - 1, c);
		color[COL_LEN - 1] = '\0';
	}

	std::ostream & operator<<(std::ostream & os,
							  const lacksDMA & rs)
	{
		os << (const baseDMA &) rs
		   << "Color: " << rs.color << std::endl;
		return os;
	}

	void lacksDMA::view() const
	{
		std::cout << *this;
	}

	// hasDMA constructors
	hasDMA::hasDMA(const char * s, const char * l,
				   int r)
				   : baseDMA(l, r)
	{
		style = new char[strlen(s) + 1];
		strcpy_s(style, strlen(s) + 1,s);
	}

	hasDMA::hasDMA(const char * s, const baseDMA & rs)
		: baseDMA(rs)
	{
		style = new char[strlen(s) + 1];
		strcpy_s(style, strlen(s) + 1, s);
	}

	hasDMA::hasDMA(const hasDMA & has)
		: baseDMA(has)
	{
		style = new char[strlen(has.style) + 1];
		strcpy_s(style, strlen(has.style) + 1, has.style);
	}

	// useful destructor
	hasDMA::~hasDMA()
	{
		delete [] style;
	}

	// overloaded '=' operator
	hasDMA & hasDMA::operator=(const hasDMA & rs)
	{
		// skip if used on itself
		if (this == &rs)
			return *this;

		// copy base portion
		baseDMA::operator=(rs);
		delete [] style;
		style = new char[strlen(rs.style) + 1];
		strcpy_s(style, strlen(rs.style) + 1, rs.style);

	}

	std::ostream & operator<<(std::ostream & os,
							  const hasDMA & rs)
	{
		os << (const baseDMA &) rs
		   << "Style: " << rs.style << std::endl;
		return os;
	}

	// ...yup...
	void hasDMA::view() const
	{
		std::cout << *this;
	}


}