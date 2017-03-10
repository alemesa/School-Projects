////////////////////////////////////////////////////////////////
// OOP244       Workshop 8: Derived Classes
// File	        Hero.h
// Version      1.0
// Date	        2016/11/17
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////

#include <iostream>

#ifndef SICT_HERO_H
#define SICT_HERO_H



	class Hero {
	protected:
		char _name[20];
		double _strength;
	public:
		Hero(char const*, double);
		Hero();
		~Hero();
		double getStrength() const;
		void display(std::ostream&) const;
		void operator-=(double strength);
		void operator+=(double strength);
		bool isEmpty() const;
	};
	bool operator<(const Hero &, const Hero &);


#endif