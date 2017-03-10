////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        Car.cpp
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include "Car.h"

namespace sict
{
	//Check speed
	void Car::speed(int value)
	{
		if (value > maxSpeed_) {
			value = maxSpeed_;
		}
		if (value < 0) {
			value = 0;
		}
		speed_ = value;

	}
	//Returns Speed
	int Car::speed() const
	{
		return speed_;
	}
	//Returns Max Speed
	int Car::maxSpeed() const
	{
		return maxSpeed_;
	}

	//Constructor 1 argument
	Car::Car(int maxSpeed)
	{
		//100 is declared on the .h
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}


}