// dma.h - ch13e3
#ifndef DMA_H_
#define DMA_H_
#include <iostream>;

namespace DMA
{

	// ABC from which baseDMA, lacksDMA, and hasDMA are derived
	class DMAABC
	{
	private:
		char * label;
		int rating;
	public:
		// this is a bit silly..... using an ABC for the given
		// exercise doesn't seem to make any sense!
		// Nonetheless we will comply and place a function
		// that is essentially a constructor.......
		void setLabelAndRating(const char * l, int r);

		// unnecessary accessors because we chose this design...........
		// not quite sure how to ensure that these values are
		// used strictly as r-values but that is the intention of
		// the extra const keywords
		const int getRating() const { return rating;}
		const char * getLabel() const { return label;}
		void freeLabel() const { delete [] label;}

		virtual void view() const = 0;
	};


	// Base class using DMA
	class baseDMA : public DMAABC
	{
	private:
	public:
		baseDMA(const char * l = "null", int r = 0);
		baseDMA(const baseDMA & rs);
		virtual ~baseDMA();
		baseDMA & operator=(const baseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os,
										 const baseDMA & rs);
		void view() const;
	};

	// derived class without DMA
	// no destructor needed
	// uses implicit copy constructor
	// uses implicit assignment operator
	class lacksDMA : public baseDMA
	{
	private:
		enum { COL_LEN = 40 };
		char color[COL_LEN];
	public:
		lacksDMA(const char * c = "blank", const char * l = "null",
				 int r = 0);
		lacksDMA(const char * c, const baseDMA & rs);
		friend std::ostream & operator<<(std::ostream & os,
										 const lacksDMA & rs);
		void view() const;
	};

	// derived class with DMA
	class hasDMA : public baseDMA
	{
	private:
		char * style;
	public:
		hasDMA(const char * s = "none", const char * l = "null",
			   int r = 0);
		hasDMA(const char * s, const baseDMA & rs);
		hasDMA(const hasDMA & has);
		~hasDMA();
		hasDMA & operator=(const hasDMA & rs);
		friend std::ostream & operator<<(std::ostream & os,
										 const hasDMA & rs);
		void view() const;
	};

}
#endif