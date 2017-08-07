// FD.h
#ifndef FDEPENDENCY_H_
#define FDEPENDENCY_H_

#include <iostream>
#include <set>
#include <string>

namespace FD
{
	class FD
	{

	private:

		std::set<std::string> leading;
		std::set<std::string> following;
		
	public:

		// constructors
		FD(std::set<std::string> X,
			std::set<std::string> Y)
			: leading(X), following(Y)
		{}

		FD(const FD & otherFD)
			:	leading(otherFD.leading),
				following(otherFD.following)
		{}

		// friends
		friend std::ostream & operator<<(std::ostream & os, FD fd)
		{
			for (std::string x : fd.leading)
				os << x << " ";
			os << "- ";
			for (std::string x : fd.following)
				os << x << " ";
			return os;
		}

		friend bool operator<(const FD & a, const FD & b)
		{
			// functional dependencies are stored via alphabetical order
			std::string temp1 = "", temp2 = "";
			for (std::string x : a.leading)
				temp1 = temp1 + x + " ";
			temp1 += "- ";
			for (std::string x : a.following)
				temp1 = temp1 + x + " ";


			for (std::string x : b.leading)
				temp2 = temp2 + x + " ";
			temp2 += "- ";
			for (std::string x : b.following)
				temp2 = temp2 + x + " ";

			return (temp1 < temp2);
		}

		// mutators / accessors
		std::set<std::string> & getRightSide() { return following; }
		std::set<std::string> & getLeftSide() { return leading; }
		
	};


}


#endif
