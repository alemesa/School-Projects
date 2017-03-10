#include <iostream>
#include "Foo.h"

using namespace std;

int main (void)
{
	Foo theFoo;
	cout << theFoo;
	theFoo.SetMsg("Hello World");
	cout << theFoo;

	return 0;
}
