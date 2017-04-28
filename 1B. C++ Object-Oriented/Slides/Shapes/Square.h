#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
protected:
	unsigned int m_length;
public:
	Square(void);
	~Square(void);
	void Draw();
	void SetLength(unsigned int length);
};

#endif