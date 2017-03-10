#include <iostream>
#include "ArrayList.h"
using namespace cornel;
using namespace std;

int main(void)
{
	ArrayList al1;
	al1.Add(10);
	al1.Add(11);
	al1.Display();
	cout << endl;

	ArrayList al2;
	al2.Add(20);
	al2.Add(21);
	al2.Display();
	cout << endl;

	al1 += al2;
	al1.Display();
	cout << endl;

	al1 += 100;
	al1.Display();
	cout << endl;
	for (unsigned int i = 0; i < al1.GetSize(); ++i)
	{
		cout << al1[i] << "  ";
	}
	cout << endl;

	ArrayList al3;
	al3 += 200;
	if (al3)
	{
		cout << "List not empty: ";
		al3.Display();
	}
	else
	{
		cout << "List empty!!";
	}
	cout << endl;

	ArrayList al4 = 300;
	if (al4)
	{
		cout << "List not empty: ";
		al4.Display();
	}
	else
	{
		cout << "List empty!!";
	}

	return 0;
}