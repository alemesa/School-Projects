#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	char m_drawSymbol;
public:
	Shape(void);
	~Shape(void);
	void SetDrawSymbol(char ch);
	void Draw();
};

#endif