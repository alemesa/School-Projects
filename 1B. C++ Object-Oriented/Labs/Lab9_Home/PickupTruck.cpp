////////////////////////////////////////////////////////////////
// OOP244       Workshop 9: Inheritance & Virtual Functions
// File	        PickupTruck.cpp
// Version      1.0
// Date	        2016/11/21
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include "PickupTruck.h"
#include <cstring>
namespace sict
{

	PickupTruck::PickupTruck()
	{
		loadAmount_ = 0;
		loadedMaterial_[0] = '\0';
	}
	void PickupTruck::load(const char* loadedMaterial, int loadAmount)
	{
		strncpy(loadedMaterial_, loadedMaterial, 31);
		loadAmount_ = loadAmount;
	}

	void PickupTruck::unload()
	{
		loadAmount_ = 0;
	}
	bool PickupTruck::isEmpty() const
	{
		bool result;
		if (loadAmount_ == 0) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}
	void PickupTruck::brake()
	{
		int brakespeed = speed() - 5;
		speed(brakespeed);
	}
	void PickupTruck::accelerate()
	{
		int acceleratespeed = speed() + 20;
		speed(acceleratespeed);
	}
	
	std::ostream&PickupTruck::display(std::ostream& ostr) const
	{
		if (isEmpty() == true) {
			ostr << "This pickup truck is not carrying any load";
		}
		else {
			ostr << "This pickup truck is carrying " << loadAmount_ << " kgs of " << loadedMaterial_;
		}
		if (speed() > 0) {
			ostr << ", traveling at the speed of " << speed() << " km/h.";
		}
		else {
			ostr << " and is parked.";
		}
		return ostr;
	}

}