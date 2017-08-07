// DisplayTime.cpp
/* Simple program to write
   the system clock time to
   a text file
*/
#include <iostream>;
#include <fstream>;
#include <string>;
#include <ctime>;
#include <Windows.h>;
#include <iomanip>;

namespace
{
	//const unsigned int TIME_LENGTH = 1000;
	//char BUF[TIME_LENGTH];
	const unsigned int NOON = 12;
	const unsigned int ABBR_SIZE = 3;
	const unsigned long MILLISECONDS_TO_MINUTES = 60000;
	const char AM[ABBR_SIZE] = "AM";
	const char PM[ABBR_SIZE] = "PM";
	const char TIME_FILE_PATH[] = "C:\\Users\\William\\Desktop\\Time.txt";
	const char CURRENT_TIME_STRING[] = "Current Time ";
	const char TIME_ZONE[] = "(EST)";
}

// helper function
void militaryToStandard(unsigned int &, std::string &);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	using std::ofstream;
	ofstream out;
	time_t rawtime;
	struct tm timeinfo;
	time ( &rawtime );
	localtime_s(&timeinfo, &rawtime);
	unsigned int hour = timeinfo.tm_hour;
	unsigned int mins = timeinfo.tm_min;
	string abbr = AM;

	// open the file to write to
	out.open(TIME_FILE_PATH);
	
	// convert from military time
	militaryToStandard(hour, abbr);

	// print time once into file using iomanipulation
	out << CURRENT_TIME_STRING << hour << ":" << std::setw(2) << std::setfill('0') << mins << " " << abbr
		<< " " << TIME_ZONE << endl;

	// close the file
	out.close();

	while(true)
	{
		// sleep for some time
		Sleep(MILLISECONDS_TO_MINUTES);

		time ( &rawtime );
		localtime_s(&timeinfo, &rawtime);
		hour = timeinfo.tm_hour;
		mins = timeinfo.tm_min;
		abbr = AM;

		// open the file to write to
		out.open(TIME_FILE_PATH);
	
		// convert from military time
		militaryToStandard(hour, abbr);
		
		// print time once into file using iomanipulation
		out << CURRENT_TIME_STRING << hour << ":" << std::setw(2) << std::setfill('0') << mins << " " << abbr << endl;

		// close the file
		out.close();
	}

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}

// convert from military time
void militaryToStandard(unsigned int & hour, std::string & abbr)
{
	if (hour >= NOON)
	{
		abbr = PM;
		if (hour > NOON)
			hour -= NOON;
	}
}