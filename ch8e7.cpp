// chapter 8 exercise 7 - ch8e7.cpp
#include <iostream>;

// herp n derp
template <class T>
void showArray(T arr[], int);

// herp the derp 2.0
template <class T>
void showArray(T * arr[], int);

// herp n derp
template <class T>
void sumArray(T arr[], int);

// herp the derp 2.0
template <class T>
void sumArray(T * arr[], int);

// structs
struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int things[6] = {13, 31, 103, 301, 310, 130};
	debts mr_E[3] = 
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];

	for (int i=0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr. E's counts of things:\n";
	showArray(things, 6);
	cout << "Sum of Mr. E's counts of things:\n";
	sumArray(things, 6);
	cout << "Listing Mr. E's debts:\n";
	showArray(pd, 3);
	cout << "Sum of Mr. E's debts:\n";
	sumArray(pd, 3);

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

template <class T>
void showArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <class T>
void showArray(T* arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for(int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}


template <class T>
void sumArray(T arr[], int n)
{
	using namespace std;
	T sum = arr[0];
	cout << "template A\n";
	for(int i = 1; i < n; i++)
		sum+=arr[i];
	cout << sum;
	cout << endl;
}

template <class T>
void sumArray(T* arr[], int n)
{
	using namespace std;
	T sum = *arr[0];
	cout << "template B\n";
	for(int i = 1; i < n; i++)
		sum+=*arr[i];
	cout << sum;
	cout << endl;
}