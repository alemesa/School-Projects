#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(void)
{
	clog << "[INFO] Student::Student()" << endl;
	this->m_age = 20;
	this->m_strName = "John Doe";
}

Student::~Student(void)
{
	clog << "[INFO] Student::~Student()" << endl;
}

ostream& operator<< (ostream& out, const Student& theStudent)
{
	clog << "[INFO] operator<<(ostream&, const Student&)" << endl;
	out << "The name is: " << theStudent.m_strName;
	out << "(" << theStudent.m_age << ")" << endl;
	return out;
}

istream& operator>>(istream& in, Student& theStudent)
{
	clog << "[INFO] operator>>(istream&, Student&)" << endl;
	if (in)
	{
		in >> theStudent.m_strName;
		in >> theStudent.m_age;
		if (in.fail())
			theStudent.m_age = 0;
	}
	return in;
}