#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

int main()
{
	ofstream theOut;
	theOut.open("./theout.txt");

	ifstream theIn;
	theIn.open("./thein.txt");

	Student theStudent;
	Student anotherStudent;
	cout << theStudent;
	theOut << theStudent;

	theIn >> theStudent;
	theIn >> anotherStudent;

	theOut << theStudent;
	theOut << anotherStudent;

	theOut.close();
	return 0;
}