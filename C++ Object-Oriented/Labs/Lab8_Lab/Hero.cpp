////////////////////////////////////////////////////////////////
// OOP244       Workshop 8: Derived Classes
// File	        Hero.cpp
// Version      1.0
// Date	        2016/11/17
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include "Hero.h"

using namespace std;



	//Arguments Constructor
	Hero::Hero(char const* name, double strength) {
		strcpy(_name, name);
		_strength = strength;
	}

	//Empty State Constructor
	Hero::Hero() {
		_strength = 0;
		_name[0] = 0;
	}

	//Check Empty State
	bool Hero::isEmpty() const {
		bool result;
		if (_name && _name[0] && _strength >= 0.00)
			result = true;
		else
			result = false;	
		return result;
	}

	//Return strength
	double Hero::getStrength() const {
		double result;
		if (_strength)
			result = _strength;
		else
			result = 0;
		return result;
	}

	//OS for the name and the strength
	void Hero::display(std::ostream& os) const {
		if (os) 
			cout << _name << " - " << _strength << endl;
	}

	//Compare both strenght
	bool operator<(const Hero& first, const Hero& second) {
		bool result;
		if (first.getStrength() < second.getStrength())
			result = true;
		else
			result = false;
		return result;
	}

	//Operator to reduce Strength
	void Hero::operator-=(double strength) {
		if (strength > _strength)
			_strength = 0;
		else 
			_strength = _strength - strength;
	}

	//Operator to add Strength
	void Hero::operator+=(double strength) {
		_strength = _strength + strength;
	}

	//Destructor
	Hero::~Hero() {}
