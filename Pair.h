// Pair.h - ch14e1 & ch14e2
// Template class
//		All template class implementation must be
// included in the header file
//		I suppose gating is still useful when
// dealing with templates since each time you
// include a Pair.h header file you automatically
// include every class that has been generated 
// using the header file (code bloating).
#ifndef PAIR_H_
#define PAIR_H_

namespace PAIR
{
	template <class T1, class T2>
	class Pair
	{
	private:
		T1 a;
		T2 b;
	public:
		T1 & first();
		T2 & second();
		T1 first() const		{ return a; }
		T2 second() const		{ return b; }
		Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval)	{}
		Pair()	{}

		//template <class T1, class T2>
		//friend bool operator==(const Pair &, const Pair &);
	};

	template <class T1, class T2>
	T1 & Pair<T1, T2>::first()
	{
		return a;
	}
	
	template <class T1, class T2>
	T2 & Pair<T1, T2>::second()
	{
		return b;
	}

}


#endif
