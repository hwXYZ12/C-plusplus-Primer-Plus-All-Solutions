// emp.h - header file for abstr_emp class and children
// ch14e5 & ch17e6
#include <iostream>;
#include <string>;

namespace EMPLOYEES
{
	static const char * DEFAULT_FIRST_NAME = "NameMe";
	static const char * DEFAULT_LAST_NAME = "NameMeToo";
	static const char * DEFAULT_JOB = "GimmeWork";
	enum classType{Employee, Manager, Fink, Highfink};

	class abstr_emp
	{
	private:
		std::string				m_fname;		// abstr_emp's first name
		std::string				m_lname;		// abstr_emp's last name
		std::string				m_job;
	public:
		abstr_emp()
				  : m_fname(DEFAULT_FIRST_NAME),
				    m_lname(DEFAULT_LAST_NAME),
					m_job(DEFAULT_JOB)
		{}
		abstr_emp(const std::string & fname,
				  const std::string & lname,
				  const std::string & job)
				  : m_fname(fname),
				    m_lname(lname),
					m_job(job)
		{}
		abstr_emp(const abstr_emp & e)
				  : m_fname(e.m_fname),
				    m_lname(e.m_lname),
					m_job(e.m_job)
		{}
		virtual void showAll() const;			// labels and shows all data
		virtual void setAll();					// prompts user for values
		virtual void writeAll(std::ostream & os); // writes data members to a file in a simple text-based format
		friend std::ostream & operator<<(std::ostream & os,
										 const abstr_emp & e);
		// just displays first and last name
		virtual ~abstr_emp() = 0;				// virtual base class
	};

	class employee : public abstr_emp
	{
	public:
		employee()
				 : abstr_emp()
		{}
		employee(const std::string & fname,
				 const std::string & lname,
				 const std::string & job)
				 : abstr_emp(fname, lname, job)
		{}
		virtual void showAll() const;
		virtual void setAll();
		virtual void writeAll(std::ostream & os);
	};


	static const int DEFAULT_IN_CHARGE_OF = 0;

	class manager : virtual public abstr_emp
	{
	private:
		int						m_inChargeOf;				// number of abstr_emps managed
	protected:
		int						inChargeOf() const		{ return m_inChargeOf; }
		int &					inChargeOf()			{ return m_inChargeOf; }
	public:
		manager()
				: abstr_emp(),
				  m_inChargeOf(DEFAULT_IN_CHARGE_OF)
		{}
		manager(const std::string & fname,
				const std::string & lname,
				const std::string & job,
				int inChargeOf)
				: abstr_emp(fname, lname, job),
				  m_inChargeOf(inChargeOf)
		{}
		manager(const abstr_emp & e,
			    int inChargeOf)
				: abstr_emp(e),
				  m_inChargeOf(inChargeOf)
		{}
		manager(const manager & ma)
				: abstr_emp(ma),
				  m_inChargeOf(ma.m_inChargeOf)
		{}
		virtual void showAll() const;
		virtual void setAll();
		virtual void writeAll(std::ostream & os);
	};


	static const char * DEFAULT_SUPERIOR = "YerDad";

	class fink : virtual public abstr_emp
	{
	private:
		std::string				m_reportsTo;			// to whom fink reports
	protected:
		const std::string reportsTo() const			{ return m_reportsTo; }
		std::string & reportsTo()					{ return m_reportsTo; }
	public:
		fink()
			 : abstr_emp(),
			   m_reportsTo(DEFAULT_SUPERIOR)
		{}
		fink(const std::string & fname,
			 const std::string & lname,
			 const std::string & job,
			 const std::string & reportsTo)
			 : abstr_emp(fname, lname, job),
			   m_reportsTo(reportsTo)
		{}
		fink(const abstr_emp & e,
			 const std::string reportsTo)
			 : abstr_emp(e),
			   m_reportsTo(reportsTo)
		{}
		fink(const fink & e)
			 : abstr_emp(e),
			   m_reportsTo(e.m_reportsTo)
		{}
		virtual void showAll() const;
		virtual void setAll();
		virtual void writeAll(std::ostream & os);
	};

	class highfink : public manager, public fink	// management fink
	{
	public:
		highfink()
				 : abstr_emp(),
				   manager(),
				   fink()
		{}
		highfink(const std::string & fname,
				 const std::string & lname,
				 const std::string & job,
				 const std::string & reportsTo,
				 int inChargeOf)
				 : abstr_emp(fname, lname, job),
				   manager(fname, lname, job, inChargeOf),
				   fink(fname, lname, job, reportsTo)
		{}
		highfink(const abstr_emp & e,
				 const std::string & reportsTo,
				 int inChargeOf)
				 : abstr_emp(e),
				   manager(e, inChargeOf),
				   fink(e, reportsTo)
		{}
		highfink(const fink & f,
				 int inChargeOf)
				 : abstr_emp(f),
				   manager(f, inChargeOf),
				   fink(f)
		{}
		highfink(const manager & m,
				 const std::string & reportsTo)
				 : abstr_emp(m),
				   manager(m),
				   fink(m, reportsTo)
		{}
		highfink(const highfink & h)
				 : abstr_emp(h),
				   manager(h),
				   fink(h)
		{}
		virtual void showAll() const;
		virtual void setAll();
		virtual void writeAll(std::ostream & os);
	};

}



