////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        Car.h
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef SICT_CAR_H_
#define SICT_CAR_H_
#include"Vehicle.h"
namespace sict
{
	// complete the declaration of the class
	// Car inherits from Vehicle
	class Car:public Vehicle
	{
	private:
		// private members go here
		int speed_;
		int maxSpeed_;

	protected:
		// protected members go here
		void speed(int value);
		int maxSpeed() const;

	public:
		// public members go here
		int speed() const;
		Car(int maxSpeed = 100);
		// new members
		virtual void accelerate();
		virtual void brake();
		virtual std::ostream& display(std::ostream& ostr) const;

	};
	std::ostream& operator<<(std::ostream &cout, const Car &obj);
}

#endif