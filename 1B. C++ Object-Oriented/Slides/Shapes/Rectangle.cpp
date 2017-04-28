#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(void)
{
	clog << "[INFO] Rectangle::Rectangle()" << endl;
	this->m_width = 20;
}

Rectangle::~Rectangle(void)
{
	clog << "[INFO] Rectangle::~Rectangle()" << endl;
}

void Rectangle::SetWidth(unsigned int width)
{
	clog << "[INFO] Rectangle::SetWidth()" << endl;
	this->m_width = width;
}

void Rectangle::Draw()
{
	clog << "[INFO] Rectangle::Draw()"  << endl;
	for (unsigned int j = 0; j < this->m_width; ++j)
	{
		cout << this->m_drawSymbol;
	}
	cout << endl;
	for (unsigned int i = 1; i < this->m_length - 1; ++i)
	{
		cout << this->m_drawSymbol;
		for (unsigned int j = 1; j < this->m_width - 1; ++j)
		{
			cout << " ";
		}
		cout << this->m_drawSymbol << endl;
	}
	for (unsigned int j = 0; j < this->m_width; ++j)
	{
		cout << this->m_drawSymbol;
	}
	cout << endl;
}