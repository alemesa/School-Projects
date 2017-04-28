#include <iostream>
#include "Shape.h"

using namespace std;

Shape::Shape(void)
{
	clog << "[INFO] Shape::Shape()" << endl;
	this->m_drawSymbol = '*';
}

Shape::~Shape(void)
{
	clog << "[INFO] Shape::~Shape()" << endl;
}

void Shape::SetDrawSymbol(char symbol)
{
	this->m_drawSymbol = symbol;
}

void Shape::Draw()
{
	clog << "[INFO] Shape::Draw()" << endl;
}