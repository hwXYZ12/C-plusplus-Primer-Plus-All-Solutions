// chapter 7 exercise 2 - ch7e2.cpp
#include <iostream>

int getScores(int*, std::ostream*, std::istream*);
void displayScores(const int*, std::ostream*, int);
double avgScore(const int*, int);
const int GOLF_SCORES = 10;

int main()
{
	using namespace std;

	int golfScores[GOLF_SCORES];
	int size = getScores(golfScores, &cout, &cin);
	displayScores(golfScores, &cout, size);

	cout << "Press ENTER to exit.";

	cin.get();
	cin.get();
	return 0;
}

// Prompts user for 10 golf scores allowing him/her to terminate early
// returns the number of golf scores
int getScores(int* scores, std::ostream* cout, std::istream* cin)
{
	*cout << "Please enter 10 golf scores. Enter 'q' or a negative value to quit." << "\n";
	int i=0;
	*cout << "Score " << (i+1) << ": ";
	while (*cin >> scores[i] && (scores[i] >= 0))
	{
		i++;
		if (i >= GOLF_SCORES)
			break;

		*cout << "Score " << (i+1) << ": ";
	}

	// Clear input
	(*cin).clear();
	while ((*cin).get() != '\n');

	// Note that i is incremented before the break
	// so that i represents the number of entered golf scores as opposed to
	// i + 1
	return i;
}

// Displays the given golf scores and the average score
void displayScores(const int* scores, std::ostream* cout, int size)
{
	if (size <= 0) 
	{
		*cout << "You have not entered any golf scores.\n";
		return;
	}

	*cout << "Here are the golf scores you've entered: ";
	for(int i=0; i < size; i++)
		*cout << scores[i] << " ";
	*cout << "\n";
	*cout << "Here is the average score: " << avgScore(scores, size) << "\n";
}

// Computes average golf score as a double
double avgScore(const int* scores, int size)
{
	double ret = 0;
	for(int i=0; i < size; i++)
	{
		ret += scores[i];
	}
	ret = ret / size;
	return ret;
}