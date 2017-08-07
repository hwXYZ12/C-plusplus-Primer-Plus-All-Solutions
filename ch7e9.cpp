// chapter 7 exercise 9 - ch7e9.cpp
#include <iostream>
#include <cstring>
using namespace std;

// constants & structs
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

/* getinfo() has two arguments: a pointer to the first element of
   an array of student structures and an int representing the
   number of elements of the array. The function solicits and
   stores data about students. It terminates input upon filling
   the array or upon encountering a blank line for the the student
   name. The function returns the actual number of array elements
   filled.
*/
int getinfo(student[], int);

/* display1() takes a student structure as an argument
   displays its contents
*/
void display1(student);

/* display2() takes the address of student structure as an
   argument and displays the structure's contents
*/
void display2(const student*);

/* display3() takes the address of the first element of an array
   of student structures and the number of array elements as
   arguments and displays the contents of the structures
*/
void display3(const student[], int);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	// clear input queue
	while(cin.get() != '\n');

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i=0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;

	cout << "Press ENTER to exit.";
	cin.get();
	return 0;
}


/* getinfo() has two arguments: a pointer to the first element of
   an array of student structures and an int representing the
   number of elements of the array. The function solicits and
   stores data about students. It terminates input upon filling
   the array or upon encountering a blank line for the the student
   name. The function returns the actual number of array elements
   filled.
*/
int getinfo(student students[], int totalStudents)
{
	int i=0;
	char temp[SLEN];
	while(i < totalStudents)
	{
		cout << "Please enter the name of Student " << i+1 << ": ";
		cin.getline(temp, SLEN);
		if (!cin)
		{
			// revert checkbit
			cin.clear();

			// some kind of error occurred!
			cout << "An error has occurred! Input terminated." << endl;
			break;

		} else if (temp[0] == '\0')
		{
			// user has entered a blank name for the student
			// thus terminating input
			cout << "A blank student name has been entered; Input terminated." << endl;
			break;
		}
		// else
		strcpy_s(students[i].fullname, temp);

		// get hobby
		cout << "Please enter a hobby of Student " << i+1 << ": ";
		cin.getline(students[i].hobby, SLEN);
		if (!cin)
		{
			cout << "An error has occurred! This student will have one obscure hobby....." << endl;

			// revert checkbit
			cin.clear();
		}

		// get ooplevel
		cout << "Please enter the OOPLevel of Student " << i+1 << ": ";
		int tempNum;
		cin >> tempNum;
		while(!cin)
		{
			// revert checkbit & clear input queue
			cin.clear();
			while(cin.get() != '\n');

			cout << "ERROR - Please enter an integer: ";
			cin >> tempNum;
		}
		students[i].ooplevel = tempNum;

		// clear input queue
		while(cin.get() != '\n');


		// finally, a students data has been successfully recorded
		// so we increment the count
		i++;

	}
	return i;
}

/* display1() takes a student structure as an argument
   displays its contents
*/
void display1(student s)
{
	cout << "Name: " << s.fullname << endl;
	cout << "Hobby: " << s.hobby << endl;
	cout << "OOPLevel: " << s.ooplevel << endl;
}

/* display2() takes the address of student structure as an
   argument and displays the structure's contents
*/
void display2(const student* s)
{
	cout << "Name: " << s->fullname << endl;
	cout << "Hobby: " << s->hobby << endl;
	cout << "OOPLevel: " << s->ooplevel << endl;
}

/* display3() takes the address of the first element of an array
   of student structures and the number of array elements as
   arguments and displays the contents of the structures
*/
void display3(const student students[], int size)
{
	for(int i=0; i < size; i++)
	{
		display2(&students[i]);
	}
}