// chapter 16 exercise 10 - ch16e10.cpp
#include <iostream>;
#include <string>;
#include <vector>;
#include <algorithm>;
#include <memory>;

using namespace std;

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool fillReview(Review & rr);
void showReview(const shared_ptr<Review> & rr);

int main()
{
	vector<shared_ptr<Review>> books;
	Review * temp = new Review(); 
	while(fillReview(*temp))
	{
		shared_ptr<Review> rptr(temp);
		books.push_back(rptr);
		temp = new Review();
	}

	if (books.size()>0)
	{
		cout << "Thank you. You entered the following "
			 << books.size() << " ratings:\n"
			 << "Rating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), showReview);
		vector<shared_ptr<Review>> booksByAlph;
		vector<shared_ptr<Review>> booksByPrice;
		vector<shared_ptr<Review>> booksByRatings;
		vector<shared_ptr<Review>> booksByOriginal;
		for(shared_ptr<Review> x: books)
		{
			booksByAlph.push_back(x);
			booksByPrice.push_back(x);
			booksByRatings.push_back(x);
			booksByOriginal.push_back(x);
		}

		sort(booksByAlph.begin(), booksByAlph.end(), operator<);
		sort(booksByPrice.begin(), booksByPrice.end(), cheaperThan);
		sort(booksByRatings.begin(), booksByRatings.end(), worseThan);

		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), showReview);

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tPrice\tBook\n";
		for_each(books.begin(), books.end(), showReview);

		// prompt user to display the ratings by either
		// a: original order
		// b: alphabetical order
		// c: increasing ratings
		// d: decreasing ratings
		// e: increasing price
		// f: decreasing price
		// quit: quit
		char in;
		cout << "Please enter a menu selection... " << endl
			 << "a: original order" << endl
			 << "b: alphabetical order" << endl
			 << "c: increasing ratings" << endl
			 << "d: decreasing ratings" << endl
			 << "e: increasing price" << endl
			 << "f: decreasing price" << endl
			 << "q: quit" << endl
			 << "Your choice: ";
		cin >> in;
		while(in != 'q')
		{
			switch(in)
			{
				case 'a':
					cout << "Original order:\nRating\tPrice\tBook\n";
					for_each(booksByOriginal.begin(), booksByOriginal.end(), showReview);
					break;
				case 'b':
					cout << "Sorted in alphabetical order:\nRating\tPrice\tBook\n";
					for_each(booksByAlph.begin(), booksByAlph.end(), showReview);
					break;
				case 'c':
					cout << "Sorted by increasing rating:\nRating\tPrice\tBook\n";
					for_each(booksByRatings.begin(), booksByRatings.end(), showReview);
					break;
				case 'd':
					cout << "Sorted by decreasing rating:\nRating\tPrice\tBook\n";
					for_each(booksByRatings.rbegin(), booksByRatings.rend(), showReview);
					break;
				case 'e':
					cout << "Sorted by increasing price:\nRating\tPrice\tBook\n";
					for_each(booksByPrice.begin(), booksByPrice.end(), showReview);
					break;
				case 'f':
					cout << "Sorted by decreasing price:\nRating\tPrice\tBook\n";
					for_each(booksByPrice.rbegin(), booksByPrice.rend(), showReview);
					break;
				default:
					in = 'q';
			}

			cout << "Please enter a menu selection... " << endl
				 << "a: original order" << endl
				 << "b: alphabetical order" << endl
				 << "c: increasing ratings" << endl
				 << "d: decreasing ratings" << endl
				 << "e: increasing price" << endl
				 << "f: decreasing price" << endl
				 << "q: quit" << endl
				 << "Your choice: ";
			cin >> in;
		}

	}
	else
	{
		cout << "No entries. ";
	}

	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if(r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool cheaperThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
	if(r1->price < r2->price)
		return true;
	else
		return false;
}

bool fillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if(rr.title=="quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;
	std::cin.get();
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if(!std::cin)
		return false;
	// get rid of rest of input line
	while(std::cin.get()!='\n');
	return true;
}

void showReview(const shared_ptr<Review> & rr)
{
	std::cout << rr->rating << "\t" << rr->price << "\t" << rr->title << std::endl;
}


