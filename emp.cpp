// emp.h - ch14e5 & ch17e6
#include "emp.h";
#include <iostream>;

namespace EMPLOYEES
{
	using std::cout;
	using std::endl;
	using std::cin;

	// abstract destructor???
	abstr_emp::~abstr_emp()
	{
	}

	void abstr_emp::showAll() const
	{
		cout << "First Name: " << m_fname << endl
			 << "Last Name: " << m_lname << endl
			 << "Job: " << m_job << endl;
	}

	void employee::showAll() const
	{
		cout << "Employee" << endl;
		abstr_emp::showAll();
	}

	void manager::showAll() const
	{
		cout << "Manager" << endl;
		abstr_emp::showAll();
		cout << "In charge of: " << m_inChargeOf << endl;
	}

	void fink::showAll() const
	{
		cout << "Fink" << endl;
		abstr_emp::showAll();
		cout << "Reports to: " << m_reportsTo << endl;
	}

	void highfink::showAll() const
	{
		cout << "HighFink" << endl;
		abstr_emp::showAll();
		cout << "In charge of: " << inChargeOf() << endl
			 << "Reports to: " << reportsTo() << endl;
	}

	void abstr_emp::setAll()
	{
		cout << "Please enter employee information." << endl
			 << "First Name: ";
		getline(cin, m_fname);
		cout << "Last Name: ";
		getline(cin, m_lname);
		cout << "Job: ";
		getline(cin, m_job);
	}

	void employee::setAll()
	{
		abstr_emp::setAll();
	}

	void manager::setAll()
	{
		abstr_emp::setAll();
		cout << "In charge of: ";
		cin >> m_inChargeOf;
	}

	void fink::setAll()
	{
		abstr_emp::setAll();
		cout << "Reports to: ";
		getline(cin, m_reportsTo);
	}

	void highfink::setAll()
	{
		abstr_emp::setAll();
		cout << "Reports to: ";
		// make use of base class mutators
		getline(cin, reportsTo());
		cout << "In charge of: ";
		cin >> inChargeOf();
	}

	std::ostream & operator<<(std::ostream & os,
							  const abstr_emp & e)
	{
		os << "Employee Info" << endl
		   << "First Name: " << e.m_fname << endl
		   << "Last Name: " << e.m_lname << endl
		   << "Job: " << e.m_job << endl;
		return os;
	}

	// write methods
	void abstr_emp::writeAll(std::ostream & os)
	{
		os << m_fname << endl
		   << m_lname << endl
		   << m_job << endl;
	}

	void employee::writeAll(std::ostream & os)
	{
		os << Employee << endl;
		abstr_emp::writeAll(os);
	}

	void manager::writeAll(std::ostream & os)
	{
		os << Manager << endl;
		abstr_emp::writeAll(os);
		os << m_inChargeOf << endl;
	}

	void fink::writeAll(std::ostream & os)
	{
		os << Fink << endl;
		abstr_emp::writeAll(os);
		os << m_reportsTo << endl;
	}

	void highfink::writeAll(std::ostream & os)
	{
		os << Highfink << endl;
		abstr_emp::writeAll(os);
		os << inChargeOf() << endl
		   << reportsTo() << endl;
	}

}
