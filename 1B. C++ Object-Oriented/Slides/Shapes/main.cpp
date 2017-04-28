#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"

int main (void)
{
	Square aSquare;
	aSquare.SetDrawSymbol('#');
	aSquare.SetLength(20);
	aSquare.Draw();

	Rectangle aRectangle;
	aRectangle.SetLength(5);
	aRectangle.SetWidth(30);
	aRectangle.SetDrawSymbol('+');
	aRectangle.Draw();

	Circle aCircle;
	aCircle.SetRadius(20);
	aCircle.SetDrawSymbol('@');
	aCircle.Draw();

	return 0;
}