// people.h - ch14e4
#ifndef PEOPLE_H_
#define PEOPLE_H_
#include <string>;
#include <cstdlib>;
#include <ctime>;

namespace PEOPLE
{
	using std::string;

	// Constants used in Person class
	static const char * DEFAULT_FIRST_NAME = "NameMe";
	static const char * DEFAULT_LAST_NAME = "NameMeToo";

	class Person
	{
	private:
		string		m_fname;
		string		m_lname;
	public:
		Person(const char * fname = DEFAULT_FIRST_NAME, const char * lname = DEFAULT_LAST_NAME)
			: m_fname(fname),
			  m_lname(lname)
		{}
		Person(const Person & p)
			: m_fname(p.m_fname),
			  m_lname(p.m_lname)
		{}
		virtual ~Person() {}
		virtual void show() const;
	};

	
	// Constants used in GunSlinger class
	static const double DEFAULT_DRAWTIME = 1.0;
	static const int DEFAULT_NOTCHES = 0;

	class GunSlinger : public virtual Person
	{
	private:
		double		m_drawtime;
		int			m_notches;
	public:
		GunSlinger(const char * fname = DEFAULT_FIRST_NAME,
				   const char * lname = DEFAULT_LAST_NAME,
				   double drawtime = DEFAULT_DRAWTIME,
				   int notches = DEFAULT_NOTCHES)
				   : Person(fname, lname),
					 m_drawtime(drawtime),
					 m_notches(notches)
		{}
		GunSlinger(const Person & p,
				   double drawtime = DEFAULT_DRAWTIME,
				   int notches = DEFAULT_NOTCHES)
				   : Person(p),
					 m_drawtime(drawtime),
					 m_notches(notches)
		{}
		GunSlinger(const GunSlinger & gs)
				   : Person(gs),
				     m_drawtime(gs.m_drawtime),
					 m_notches(gs.m_notches)
		{}
		double draw() const				{ return m_drawtime; }
		void show() const;
	};

	// class constant
	static bool generatorOn = false;

	class PokerPlayer : public virtual Person
	{
	public:
		PokerPlayer(const char * fname = DEFAULT_FIRST_NAME,
				    const char * lname = DEFAULT_LAST_NAME)
				    : Person(fname, lname)
		{
			// seed generator
			if (!generatorOn)
			{
				std::srand(time(nullptr));
				generatorOn = true;
			}
		}
		PokerPlayer(const Person & p)
			: Person(p)
		{
			// seed generator
			if (!generatorOn)
			{
				std::srand(time(nullptr));
				generatorOn = true;
			}
		}
		PokerPlayer(const PokerPlayer & p)
			: Person(p)
		{
			// seed generator
			if (!generatorOn)
			{
				std::srand(time(nullptr));
				generatorOn = true;
			}
		}
		int draw() const				{ return rand() % 52 + 1; }
	 };

	class BadDude : public virtual PokerPlayer, public virtual GunSlinger
	{
	public:
		BadDude(const char * fname = DEFAULT_FIRST_NAME,
				const char * lname = DEFAULT_LAST_NAME,
				double drawtime = DEFAULT_DRAWTIME,
				int notches = DEFAULT_NOTCHES)
				: Person(fname, lname),
				  PokerPlayer(fname, lname),
				  GunSlinger(fname, lname, drawtime, notches)
		{}
		// Many of these constructors are redundant since
		// there are no private data members to be initialized
		// in the PokerPlayer class. Nonetheless we'll program
		// these unnecessary constructors as if we needed them.
		BadDude(const Person & p,
				double drawtime = DEFAULT_DRAWTIME,
				int notches = DEFAULT_NOTCHES)
				: Person(p),
				  PokerPlayer(p),
				  GunSlinger(p, drawtime, notches)
		{}
		BadDude(const PokerPlayer & p,
				double drawtime = DEFAULT_DRAWTIME,
				int notches = DEFAULT_NOTCHES)
				: Person(p),
				  PokerPlayer(p),
				  GunSlinger(p, drawtime, notches)
		{}
		BadDude(const GunSlinger & s)
				: Person(s),
				  PokerPlayer(s),
				  GunSlinger(s)
		{}
		BadDude(const BadDude & b)
				: Person(b),
				  PokerPlayer(b),
				  GunSlinger(b)
		{}

		double gDraw() const			{ return GunSlinger::draw(); }
		int cDraw() const				{ return PokerPlayer::draw(); }
		void show() const;
	};




}
#endif