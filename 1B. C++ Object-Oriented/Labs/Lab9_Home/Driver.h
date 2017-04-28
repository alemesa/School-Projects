////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        Driver.h
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_
#include "Car.h"

namespace sict
{
	class Driver:public Car
	{
	private:
		// private members go here
		char name_[31];
		Car& car_;

	public:
		// public members go here
		Driver(const char* name, Car& theCar);
		void drive();
		void stop();
		void showStatus();

	};
}
#endif