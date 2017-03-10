#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
class Circle : public Shape
{
protected:
	unsigned int m_radius;
public:
	Circle(void);
	~Circle(void);
	void SetRadius(unsigned int);
	void Draw();
};

#endif