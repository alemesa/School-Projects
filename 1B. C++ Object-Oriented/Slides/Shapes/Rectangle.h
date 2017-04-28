#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Square.h"

class Rectangle : public Square
{
protected:
	unsigned int m_width;
public:
	Rectangle(void);
	~Rectangle(void);

	void SetWidth(unsigned int width);
	void Draw();
};

#endif