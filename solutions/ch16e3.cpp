// ch16e3 - chapter 16 exercise 3
#include <iostream>;
#include <string>;
#include <cstdlib>;
#include <ctime>;
#include <cctype>;
#include <vector>;
#include <fstream>;

std::vector<std::string> & parseTextforWords(std::vector<std::string> & words,
											 std::ifstream & iFileStream)
{
	using std::string;
	string temp;
	while(!iFileStream.eof())
	{
		iFileStream >> temp;
		words.push_back(temp);
	}
	return words;
}


int main()
{
	using std::string;
	using std::vector; 
	using std::ifstream;
	using std::cout;
	using std::cin;
	using std::endl;
	using std::tolower;
	std::srand(std::time(nullptr));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while(play=='y')
	{

		// clear input queue
		cin.get();

		// retrieve a filepath and open a file from the user
		string filePath;
		ifstream fStream;
		cout << "Please enter the filepath of the file containing the words "
			 << "you'd like to use in this game: ";
		getline(cin, filePath);
		fStream.open(filePath);
		while(!fStream.good())
		{
			cout << "The file couldn't be opened. Please enter another filepath: ";
			getline(cin, filePath);
			fStream.clear();
			fStream.open(filePath);
		}

		// parse the text file and populate a list of words
		vector<string> wordlist;
		wordlist = parseTextforWords(wordlist, fStream);

		string target = wordlist[std::rand()%wordlist.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			 << " letters, and you guess\n"
			 << "one letter at a time. You get " << guesses
			 << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while(guesses>0&&attempt!=target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if(badchars.find(letter)!=string::npos
			   ||attempt.find(letter)!=string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if(loc==string::npos)
			{
				cout << "Oh, bad guess:\n";
				--guesses;
				badchars+=letter;	// add to string
			}
			else
			{
				cout << "Good guess:\n";
				attempt[loc]=letter;
				// check if letter appears again
				loc = target.find(letter, loc+1);
				while(loc!=string::npos)
				{
					attempt[loc]=letter;
					loc=target.find(letter, loc+1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if(attempt!=target)
			{
				if(badchars.length()>0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		} // while(guesses>0&&attempt!=target)

		if(guesses>0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);

	} // while(play=='y')

	cout << "Press ENTER to exit.";
	cin.get();
	cin.get();
	return 0;
}
