////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        Driver.cpp
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "Driver.h"


using namespace std;
namespace sict
{
	Driver::Driver(const char* name, Car& theCar) : car_(theCar)
	{
		strncpy(name_, name, 31);
		car_ = theCar;
	}
	void Driver::stop()
	{
		while (car_.speed() != 0) {
			car_.brake();
		}
		showStatus();

	}
	void Driver::drive()
	{
		car_.accelerate();
		car_.brake();
		showStatus();
	}
	
	void Driver::showStatus()
	{
		std::cout << name_ << " is driving this car." << std::endl;
		std::cout << car_ << std::endl;
	}


}
