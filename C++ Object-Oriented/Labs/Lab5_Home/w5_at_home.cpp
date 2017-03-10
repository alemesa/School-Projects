// OOP244 Workshop 5: Classes with resources 
// File: w5_at_home.cpp
// Version: 1.0
// Date: 2016/02/15
// Author: Fardad Soleimanloo
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Contact.h"
using namespace ict;

int main() {
	Contact c("Empty Contact", 3);
	c.display();
	cout << "Enter Contact information: " << endl;
	c.read();
	c.display();
	cout << "Please wait";
	for (int i = 0; i < 1000000; i++) {
		Contact cp = c;
		c = cp;
		if (!(i % 100000)) cout << ".";
	}
	cout << endl;
	c.display();
	return 0;
}


