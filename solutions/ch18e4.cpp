// chapter 18 exercise 4 - ch18e4.cpp
#include <iostream>;
#include <list>;
#include <iterator>;
#include <algorithm>;

void outint(int n) { std::cout << n << " "; }

int main()
{

	using std::list;
	using std::cout;
	using std::endl;

	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);
	// c++11 can use the following instead 
	// list<int> yadayada = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	// list<int> etcetera { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };

	auto outint = [](int n){ std::cout << n << " "; };

	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	yadayada.remove_if([](int x){return x > 100; });				// use a named function object
	etcetera.remove_if([](int x){return x > 200; });				// construct a function object
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}