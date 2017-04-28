#include <iostream>
#include "Pet.h"

using namespace std;

Pet::Pet(void)
{
	clog << "[INFO] Pet::Pet(void)" << endl;
}

Pet::Pet(const Pet& other)
{
	clog << "[INFO] Pet::Pet(const Pet&)" << endl;
	this->m_name = other.m_name;
}

Pet::~Pet(void)
{
	clog << "[INFO] Pet::~Pet(void)" << endl;
}

void Pet::SetName(string name)
{
	clog << "[INFO] Pet::SetName(string)" << endl;
	this->m_name = name;
}
/*
void Pet::Move()
{
	clog << "[INFO] void Pet::Move()" << endl;
}
*/
