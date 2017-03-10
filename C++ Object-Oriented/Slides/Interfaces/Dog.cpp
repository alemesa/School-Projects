#include <iostream>
#include "Dog.h"

using namespace std;

Dog::Dog(void)
{
	clog << "[INFO] Dog::Dog(void)" << endl;
}

Dog::Dog(const Dog& other) : Pet(other)
{
	clog << "[INFO] Dog::Dog(const Dog&)" << endl;
}

Dog::~Dog(void)
{
	clog << "[INFO] Dog::~Dog(void)" << endl;
}

void Dog::Move()
{
	clog << "[INFO] Dog::Move()" << endl;
}

void Dog::Serialize(ostream& out)
{
	clog << "[INFO] Dog::Serialize(ostream&)" << endl;
	out << this->m_name;
}

void Dog::Deserialize(istream& in)
{
	clog << "[INFO] Dog::Deserialize(istream&)" << endl;
	in >> this->m_name;
}
