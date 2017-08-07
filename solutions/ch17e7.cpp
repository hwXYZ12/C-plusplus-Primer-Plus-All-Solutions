// chapter 17 exercise 7 - ch17e7.cpp
#include <iostream>;
#include <fstream>;
#include <string>;
#include <vector>;
#include <algorithm>;

using namespace std;

void showStr(const string & s)
{
	cout << s << endl;
}

class Store
{
private:
	ofstream * m_writeTo;
public:
	Store(ofstream & writeTo) : m_writeTo(&writeTo) {}
	void operator()(const string &);
};

void Store::operator()(const string & s)
{
	std::size_t len = s.size();
	m_writeTo->write((char *) &len, sizeof(std::size_t)); 
	m_writeTo->write(s.data(), len);
}

void getStrs(ifstream & input, vector<string> & vstr)
{
	int len = 0;
	char c;
	string temp;
	while(input.good())
	{
		len=0;
		temp="";
		input.read((char *) &len, sizeof(std::size_t));
		// read in one character at a time
		for(int i=0; i<len; ++i)
		{
			input.read(&c, 1);
			temp += c;
		}
		if(input.good())
			vstr.push_back(temp);
	}
}


int main()
{
	vector<string> vstr;
	string temp;

	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while(getline(cin, temp) && temp[0] != '\0')
		vstr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vstr.begin(), vstr.end(), showStr);

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vstr.begin(), vstr.end(), Store(fout));
	fout.close();

	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if(!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	getStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), showStr);

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}