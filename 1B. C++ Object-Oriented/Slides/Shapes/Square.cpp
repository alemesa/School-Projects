#include <iostream>
#include "Square.h"
using namespace std;

Square::Square(void)
{
	clog << "[INFO] Square::Square()" << endl;
	this->m_length = 10;
}


Square::~Square(void)
{
	clog << "[INFO] Square::~Square()" << endl;
}

void Square::SetLength(unsigned int length)
{
	this->m_length = length;
}

void Square::Draw()
{
	clog << "[INFO] Square::Draw()"  << endl;
	for (unsigned int j = 0; j < this->m_length; ++j)
	{
		cout << this->m_drawSymbol;
	}
	cout << endl;
	for (unsigned int i = 1; i < this->m_length - 1; ++i)
	{
		cout << this->m_drawSymbol;
		for (unsigned int j = 1; j < this->m_length - 1; ++j)
		{
			cout << " ";
		}
		cout << this->m_drawSymbol << endl;
	}
	for (unsigned int j = 0; j < this->m_length; ++j)
	{
		cout << this->m_drawSymbol;
	}
	cout << endl;
}
