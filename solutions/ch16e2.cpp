// ch16e2 - chapter 16 exercise 2
#include <iostream>;
#include <string>;
#include <cctype>;

std::string & prepString(std::string & s)
{
	// create a temporary copy of s
	using std::string;
	string temp(s);

	// rebuild s using temp as a guide
	int j=0;
	for(int i=0;i<temp.size();++i)
	{
		if(isalpha(temp[i]))
		{
			if(isupper(temp[i]))
				s[j] = tolower(temp[i]);
			else
				s[j] = temp[i];
			++j;
		}
	}
	// resize s
	s.resize(j);

	return s;
}


bool isPalindrome(std::string & s)
{
	// checks that the ith character from the front of the
	// string matches the ith character from the back of the
	// string.
	for(int i=0, j=s.size()-1; i<j; ++i, --j)
	{
		if (s[i]!=s[j])
			return false;
	}
	return true;
}


int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;

	string temp;
	cout << "Enter a palindrome (q to quit): ";
	getline(cin, temp);
	while(temp != "q")
	{
		// prep string using helper function
		temp = prepString(temp);
		if (isPalindrome(temp))
			cout << "Why yes, that is a palindrome!" << endl;
		else
			cout << "That's not a palindrome!" << endl;
		cout << "Enter a palindrome (q to quit): ";
		getline(cin, temp);
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
