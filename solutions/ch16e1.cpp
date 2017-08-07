// ch16e1 - chapter 16 exercise 1
#include <iostream>;
#include <string>;

bool isPalindrome(std::string & s)
{
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
	cin >> temp;
	while(temp != "q")
	{
		if (isPalindrome(temp))
			cout << "Why yes, that is a palindrome!" << endl;
		else
			cout << "That's not a palindrome!" << endl;
		cout << "Enter a palindrome (q to quit): ";
		cin >> temp;
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}
