////////////////////////////////////////////////////////////////
// OOP244       Workshop 8: Derived Classes
// File	        SuperHero.h
// Version      1.0
// Date	        2016/11/17
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////

#include <iostream>
#include "Hero.h"

#ifndef SUPER_HERO_H
#define SUPER_HERO_H



	class SuperHero : public Hero {
		double _strength_multi;
	public:
		SuperHero() : Hero() {
			_strength_multi = -1;
		}
		SuperHero(const char* supname, double supstrength, double supmulti);
		double getStrength();
		void operator*=(SuperHero& battle);
		void display(std::ostream& os) const;

	};



#endif