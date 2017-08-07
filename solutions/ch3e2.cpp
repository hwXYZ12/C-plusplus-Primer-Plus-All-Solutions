// chapter 2 exercise 2 - ch2e2.cpp
#include <iostream>
using namespace std;
const int INCHES_PER_FOOT = 12;
const double METERS_PER_INCH = 0.0254;
const double POUNDS_PER_KILOGRAM = 2.2;

double computeBMI(double height, double mass)
{
	return mass / (height * height);
}

int main()
{
	cout << "Enter your height in feet and inches (as integers).\n";
	cout << "Feet: ______\b\b\b\b\b\b";
	int feet;
	cin >> feet;
	cout << "Inches: ______\b\b\b\b\b\b";
	int inches;
	cin >> inches;
	int height = feet * INCHES_PER_FOOT + inches;
	double meters = height * METERS_PER_INCH;

	cout << "Enter your weight in pounds: ______\b\b\b\b\b\b";
	double weight;
	cin >> weight;
	double kilos = weight / POUNDS_PER_KILOGRAM;

	cout << "Your BMI is: " << computeBMI(meters, kilos) << endl;

	cin.get();
	cout << "Please press ENTER to exit.";
	cin.get();
	return 0;
}