////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        SportCar.cpp
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include "SportCar.h"
#include "Car.h"
#include "Vehicle.h"

namespace sict
{

	SportCar::SportCar()
	{
		noOfPassengers_ = 1;
	}
	SportCar::SportCar(int maxSpeed, int passengers) : Car(maxSpeed)
	{
		noOfPassengers_ = passengers;
	}

	
	void SportCar::brake()
	{
		int brakespeed = speed() - 10;
		speed(brakespeed);
	}
	void SportCar::accelerate()
	{
		int acceleratespeed = speed() + 40;
		speed(acceleratespeed);
	}
	std::ostream & SportCar::display(std::ostream & ostr) const
	{
		if (speed() > 0) {
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is traveling at a speed of " << speed() << " km/h.";
		}
		else {
			ostr << "This sport car is carrying " << noOfPassengers_ << " passengers and is parked.";
		}
			return ostr;
	}

}