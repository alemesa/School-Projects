////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        Vehicle.h
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_
#include<iostream>
namespace sict
{
	// complete the declaration of the class
	// Main Class
	class Vehicle
	{
	public:
		// public members go here
		virtual void accelerate() = 0;
		virtual void brake() = 0;
		virtual std::ostream& display(std::ostream& ostr) const = 0;

	};
}
#endif