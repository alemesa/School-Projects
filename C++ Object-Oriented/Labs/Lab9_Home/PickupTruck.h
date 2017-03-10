////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        PickupTruck.h
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef SICT_TRUCK_H_
#define SICT_TRUCK_H_
#include "Car.h"

namespace sict
{
	// complete the declaration of the class
	// PickupTruck inherits from Car
	class PickupTruck:public Car
	{
	private:
		// private members go here
		int loadAmount_;
		char loadedMaterial_[31];

	public:
		// public members go here
		PickupTruck();
		void load(const char* loadedMaterial, int loadAmount);
		void unload();
		bool isEmpty() const;

		// pure virtual members from base class go here
		void accelerate();
		void brake();
		std::ostream& display(std::ostream& ostr) const;

		


	};
}
#endif