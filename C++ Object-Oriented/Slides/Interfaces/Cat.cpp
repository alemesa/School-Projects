#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat(void)
{
	clog << "[INFO] Cat::Cat()" << endl;
}


Cat::~Cat(void)
{
	clog << "[INFO] Cat::~Cat()" << endl;
}

void Cat::Move()
{
	clog << "[INFO] Cat::Move()" << endl;
}