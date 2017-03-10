#include <iostream>
#include "String.h"
using namespace std;

int main (void)
{
	String str1;
	str1.Set("Hi");
	cout << "str1: ";
	str1.Display();

	{
		String str2 = str1;
		cout << "str2: ";
		str2.Display();
	}

	cout << "str1: ";
	str1.Display();
	return 0;
}
