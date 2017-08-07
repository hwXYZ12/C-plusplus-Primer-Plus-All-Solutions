// CSE 305 chapter 6 exercise 19 - e6.19.cpp
#include <iostream>
#include "FD.h"
#include <fstream>
#include <string>
#include <set>
#include <vector>

static std::ofstream out;
static std::ifstream in;
static const char fileNameOut[] = "e6.19out.txt";
static const char fileNameIn[] = "e6.19in.txt";

void splitRightSide(std::set<FD::FD> & d);
bool isSubset(std::set<std::string> & a, std::set<std::string> & b);
std::set<std::string> computeAttributeClosure(std::set<std::string> & X, std::set<FD::FD> & d);
bool entails(std::set<FD::FD> & d, FD::FD & f);
void checkLeftSideRedundancy(std::set<FD::FD> & d);
void checkRedundantDependencies(std::set<FD::FD> & d);

int main()
{

	using std::cout;
	using std::endl;
	using std::vector;
	using std::string;
	using std::getline;
	using FD::FD;
	using std::set;

	in.open(fileNameIn);
	out.open(fileNameOut);

	// read in the input
	vector<string> input;
	string x;
	while (getline(in, x))
		input.push_back(x);

	/*	functional dependencies input is in the following format
		the first attribute set is whitespace separated
		and the characters " - " signal
		the start of the next attribute set
		and the next attribute set is also whitespace separated
	*/
	string temp;
	set<FD> dependencies;
	set<string> leading;
	set<string> following;
	bool firstSet = true;
	for (string x : input)
	{
		// read in line by line and populate leading
		// and following attribute sets
		firstSet = true;
		for (int i = 0; i < x.size(); ++i)
		{
			if (!isspace(x[i]))
			{
				temp += x[i];
			}
			else
			{
				// check that the next character isn't '-'
				// note that if we are looking at the end of
				// the string then we don't worry about switching
				// sets
				if (i + 1 < x.size() && x[i + 1] == '-')
				{
					// switch sets and ignore the next few characters
					firstSet = false;
					leading.emplace(temp);
					i += 2;
				}
				else
				{
					if (firstSet)
						leading.emplace(temp);
					else
						following.emplace(temp);
				}
				temp = "";
			}
		}

		// don't forget to add the last attribute
		// of the FD!
		following.emplace(temp);
		temp = "";

		// emplaces an FD with the leading and following sets
		// that had been read off the input and clears the variables
		dependencies.emplace(FD(leading, following));
		leading.clear();
		following.clear();
	}

	// first step of computing a minimal cover
	splitRightSide(dependencies);

	// second step of computing a minimal cover
	checkLeftSideRedundancy(dependencies);

	// third step of computing a minimal cover
	checkRedundantDependencies(dependencies);

	// print resulting set of functional dependencies
	for (FD x : dependencies)
	{
		out << x << endl;
		cout << x << endl;
	}

	// test cases
	set<string> t1, t2;
	t1.emplace("X");
	t1.emplace("Z");
	t1.emplace("A");
	t2.emplace("Y");
	t2.emplace("B");
	FD test(t1, t2);
	entails(dependencies, test) ? cout << "Yes" << endl : cout << "No" << endl;

	t1.clear();
	t2.clear();
	t1.emplace("Y");
	t1.emplace("A");
	t1.emplace("B");
	t2.emplace("X");
	t2.emplace("Z");
	t2.emplace("Y");
	t2.emplace("A");
	t2.emplace("B");
	FD lossless1(t1, t2);
	entails(dependencies, lossless1) ? cout << "Yes" << endl : cout << "No" << endl;

	t1.clear();
	t2.clear();
	t1.emplace("Y");
	t1.emplace("A");
	t1.emplace("B");
	t2.emplace("C");
	t2.emplace("G");
	t2.emplace("W");
	t2.emplace("Y");
	t2.emplace("A");
	t2.emplace("B");
	FD lossless2(t1, t2);
	entails(dependencies, lossless2) ? cout << "Yes" << endl : cout << "No" << endl;

	set<string> z = computeAttributeClosure(t1, dependencies);
	for (string s : z)
		cout << s << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}

/*	for each functional dependency f in the set d we
	will split the right side of the dependency into
	dependencies of the form X->A where X is the
	attribute set on the left of f and the A is a single attribute
	of the attribute set on the right of f
*/
void splitRightSide(std::set<FD::FD> & d)
{
	using FD::FD;
	using std::set;
	using std::string;

	// construct a new set to populate and
	// set the return value to that set
	set<FD> ret;
	set<string> temp;

	for (FD x : d)
	{
		for (string s : x.getRightSide())
		{
			temp.emplace(s);
			ret.emplace(FD(x.getLeftSide(), temp));
			temp.clear();
		}
	}

	d.clear();
	d = ret;
}

// computes the attribute closure of the set of attributes X
// using the set of functional dependencies d
// This algorithm is taken from our class textbook.
std::set<std::string> computeAttributeClosure(std::set<std::string> & X, std::set<FD::FD> & d)
{
	using std::string;
	using std::set;
	using FD::FD;

	set<string> ret = X;
	bool on = true;
	while (on)
	{
		// loop will terminate by default if the closure has been found
		// to be complete
		on = false;

		for (FD z : d)
		{
			if (isSubset(z.getLeftSide(), ret) && !isSubset(z.getRightSide(), ret))
			{
				// union ret with the right side of the fd
				for (string s : z.getRightSide())
				{
					if (ret.find(s) == ret.end())
						ret.emplace(s);
				}

				// continue the loop as the closure may not be complete
				on = true;
			}
		}
	}

	return ret;

}

// a is a subset of b
bool isSubset(std::set<std::string> & a, std::set<std::string> & b)
{
	using std::string;
	using std::set;

	for (string s : a)
	{
		if (b.find(s) == b.end())
			return false;
	}
	return true;
}

// check entailment of an FD f in a set of
// functional dependencies d
inline bool entails(std::set<FD::FD> & d, FD::FD & f)
{
	return isSubset(f.getRightSide(), computeAttributeClosure(f.getLeftSide(),d));
}

/*	Checks for redundancy of attributes on the left
	side of the dependencies in the set d. If a redundant
	attribute is located in a dependency then the attribute
	is removed from the left side of the dependency.
*/
void checkLeftSideRedundancy(std::set<FD::FD> & d)
{
	using FD::FD;
	using std::string;
	using std::set;

	set<string> temp;
	auto pt2 = d.end();
	for (auto pt = d.begin(); pt != pt2; ++pt)
	{
		FD f = *pt;
		auto end = f.getLeftSide().end();
		for (auto i = f.getLeftSide().begin(); i != end; ++i)
		{
			temp = f.getLeftSide();
			temp.erase(*i);
			if (entails(d, FD(temp, f.getRightSide())))
			{
				f.getLeftSide().erase(*i);
				i = f.getLeftSide().begin();
				end = f.getLeftSide().end();

				// f is not the actual object
				// contained in d, thus we must edit d
				d.erase(*pt);
				d.emplace(f);
				pt = d.begin();
				pt2 = d.end();
			}
		}
	}
}

/*	Checks for redundant dependencies in the set
	and removes them.
*/
void checkRedundantDependencies(std::set<FD::FD> & d)
{
	using FD::FD;
	using std::string;
	using std::set;

	set<FD> temp;
	auto end = d.end();
	for (auto i = d.begin(); i != end; ++i)
	{
		temp = d;
		temp.erase(*i);
		FD x = *i;
		if (entails(temp, x))
		{
			d.erase(*i);
			i = d.begin();
			end = d.end();
		}
	}
}

