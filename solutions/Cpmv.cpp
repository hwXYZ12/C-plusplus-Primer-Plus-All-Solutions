// Cpmv.cpp - ch18e2
#include "Cpmv.h";
#include <iostream>;

namespace CPMV
{
	using namespace std;

	// default constructor
	Cpmv::Cpmv() : pi(nullptr) { cout << "Cpmv() called." << endl; }

	// constructor
	Cpmv::Cpmv(string q, string z)
	{
		cout << "Cpmv(" << q << ", " << z << ") called." << endl; 
		pi = new Info();
		pi->qcode = q;
		pi->zcode = z;
	}

	// copy constructor
	Cpmv::Cpmv(const Cpmv & cp)
	{
		pi = new Info();
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		cout << "Cpmv copy constructor called with info "
			<< pi->qcode << ", " << pi->zcode << endl;
	}

	// move constructor
	// this object becomes the rvalued object without
	// creating a new object
	Cpmv::Cpmv(Cpmv && mv)
	{
		pi = mv.pi;
		mv.pi = nullptr;
		cout << "Cpmv move constructor called with info "
			 << pi->qcode << ", " << pi->zcode << endl;
	}

	// destructor
	Cpmv::~Cpmv()
	{
		if (pi != nullptr)
			cout << "Cpmv destructor called with info "
				 << pi->qcode << ", " << pi->zcode << endl;
		else
			cout << "Cpmv destructor called with a nullptr." << endl;
		delete pi;
	}

	// assignment operator
	Cpmv & Cpmv::operator=(const Cpmv & cp)
	{
		if (this == &cp)
			return *this;
		delete pi;
		pi = new Info();
		pi->qcode = cp.pi->qcode;
		pi->zcode = cp.pi->zcode;
		cout << "Cpmv operator= called with info "
			<< pi->qcode << ", " << pi->zcode << endl;
	}

	// move assignment operator
	Cpmv & Cpmv::operator=(Cpmv && mv)
	{
		if(this == &mv)
			return *this;
		delete pi;
		pi = mv.pi;
		mv.pi = nullptr;
		cout << "Cpmv move operator= called with info "
			<< pi->qcode << ", " << pi->zcode << endl;
	}

	Cpmv Cpmv::operator+(const Cpmv & obj) const
	{
		pi->qcode += obj.pi->qcode;
		pi->zcode += obj.pi->zcode;
		cout << "Cpmv operator+ called with info "
			<< pi->qcode << ", " << pi->zcode << endl;
		return *this;
	}

	void Cpmv::display() const
	{
		cout << "Cpmv display called." << endl;
		cout << "Cpmv qcode: " << pi->qcode << endl
			 << "Cpmv zcode: " << pi->zcode << endl;
	}

}



