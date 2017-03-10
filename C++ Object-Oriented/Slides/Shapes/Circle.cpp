#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(void)
{
	clog << "[INFO] Circle::Circle()" << endl;
	this->m_radius = 5;
}


Circle::~Circle(void)
{
	clog << "[INFO] Circle::~Circle()" << endl;
}

void Circle::SetRadius(unsigned int radius)
{
	clog << "[INFO] Circle::SetRadius(unsigned int)" << endl;
	this->m_radius = radius;
}

void Circle::Draw()
{
	clog << "[INFO] Circle::Draw()" << endl;
	for (unsigned int i = 0; i <= 2 * this->m_radius; i++)
	{
		for (unsigned int j = 0; j <= 2 * this->m_radius; j++)
		{
			double distance_to_centre = sqrt((i - this->m_radius)*(i - this->m_radius) + (j - this->m_radius)*(j - this->m_radius));
			if (distance_to_centre > this->m_radius - 0.5 && distance_to_centre < this->m_radius + 0.5)
			{
				cout << this->m_drawSymbol;
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
