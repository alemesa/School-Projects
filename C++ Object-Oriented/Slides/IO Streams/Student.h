#ifndef STUDENT_H
#define STUDENT_H
#include <ostream>
#include <string>

class Student
{
	std::string m_strName;
	unsigned int m_age;
public:
	Student(void);
	~Student(void);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
};

#endif