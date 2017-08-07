// chapter 14 exercise 3 - ch14e3.cpp
#include <iostream>;
#include "workerMI.h";
#include "queue.h";
static const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using QUEUE::Queue;
	using namespace WORKER;

	Queue<Worker *> lolas(SIZE);

	int ct;
	Worker * w = NULL;
	for (ct = 0; ct < SIZE; ++ct)
	{
		char choice;
		cout << "Enter the employee category:\n"
			 << "w: waiter s: singer "
			 << "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
		case 'w':	w = new Waiter;
					lolas.enqueue(w);
					break;
		case 's':	w = new Singer;
					lolas.enqueue(w);
					break;
		case 't':	w = new SingingWaiter;
					lolas.enqueue(w);
					break;
		}
		cin.get();
		w->set();

	}

	cout << "\nHere is your staff:\n";
	int i;
	for(int i=0; i < ct; ++i)
	{
		cout << endl;
		lolas.dequeue(w);
		w->show();
		delete w;
	}

	// clear input queue
	while(cin.get()!='\n');
	
	cout << endl << "Press ENTER to exit.";
	cin.get();
	return 0;
}
