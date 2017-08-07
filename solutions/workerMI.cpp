// workerMI.cpp - ch14e3
#include "workerMI.h";
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

namespace WORKER
{

	// Worker methods
	Worker::~Worker() {}

	// protected methods
	void Worker::data() const
	{
		cout << "Name: " << fullname << endl;
		cout << "Employee ID: " << id << endl;
	}

	void Worker::get()
	{
		getline(cin, fullname);
		cout << "Enter worker's ID: ";
		cin >> id;
		while (cin.get() != '\n');
	}


	// Waiter methods
	void Waiter::set()
	{
		cout << "Enter waiter's name: ";
		Worker::get();
		get();
	}

	void Waiter::show() const
	{
		cout << "Category: waiter\n";
		Worker::data();
		data();
	}

	// protected methods
	void Waiter::data() const
	{
		cout << "Panache rating: " << panache << endl;
	}

	void Waiter::get()
	{
		cout << "Enter waiter's panache rating: ";
		cin >> panache;
		while(cin.get() != '\n');
	}


	// Singer methods

	char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto",
										 "soprano", "bass", "baritone", "tenor"};

	void Singer::set()
	{
		cout << "Enter singer's name: ";
		Worker::get();
		get();
	}

	void Singer::show() const
	{
		cout << "Category: singer\n";
		Worker::data();
		data();
	}

	// protected methods
	void Singer::data() const
	{
		cout << "Vocal range: " << pv[voice] << endl;
	}

	void Singer::get()
	{
		cout << "Enter number for singer's vocal range:\n";
		int i;
		for(i=0; i < Vtypes; ++i)
		{
			cout << i << ": " << pv[i] << "   ";
			if(i%4==1)
				cout << endl;
		}
		if(i%4!=0)
			cout << '\n';
		cin >> voice;
		while(cin.get()!='\n');
	}


	// SingingWaiter methods
	void SingingWaiter::set()
	{
		cout << "Enter singing waiter's name: ";
		Worker::get();
		get();
	}

	void SingingWaiter::show() const
	{
		cout << "Category: singing waiter\n";
		Worker::data();
		data();
	}

	// protected methods
	void SingingWaiter::data() const
	{
		Singer::data();
		Waiter::data();
	}

	void SingingWaiter::get()
	{
		Singer::get();
		Waiter::get();
	}


}