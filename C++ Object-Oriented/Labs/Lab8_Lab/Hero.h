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
using namespace std;

#ifndef SICT_HERO_H
#define SICT_HERO_H



	class Hero {
	private:
		char _name[20];
		double _strength;
		bool isEmpty() const;

	public:
		Hero(char const*, double);
		Hero();
		~Hero();
		double getStrength() const;
		void display(std::ostream&) const;
		void operator-=(double strength);
		void operator+=(double strength);
	};

	bool operator<(const Hero &, const Hero &);


#endif