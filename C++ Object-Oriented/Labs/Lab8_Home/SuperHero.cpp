////////////////////////////////////////////////////////////////
// OOP244       Workshop 8: Derived Classes
// File	        SuperHero.cpp
// Version      1.0
// Date	        2016/11/17
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////

#include <iostream>
#include "SuperHero.h"


using namespace std;



	//Arguments Constructor
	SuperHero::SuperHero(const char* supname, double supstrength, double supmulti) :
		Hero(supname, supstrength) {

		if (supstrength < 0 || supmulti < 0) 
			*this = SuperHero();
		else 
			_strength_multi = supmulti;
	}
	//Get strength
	double SuperHero::getStrength() {
		double result = Hero::getStrength();
		return result;
	}

	//Implement the battle portion
	//Add the strengths and the loser goes to empty state
	void SuperHero::operator*=(SuperHero& battle) {
		if (_strength < battle._strength) {
			battle._strength = battle._strength + _strength ;
			_strength = -1;
			_name[0] = '\0';
		}
		else {
			_strength = _strength + battle._strength;
			battle._strength = -1;
			battle._name[0] = '\0';
		}
	}

	//Display the winner
	void SuperHero::display(std::ostream& os) const {
		if (!isEmpty()) {
			os << "living superhero! ";
			Hero::display(os);
		}
		else 
			cout << "deceased superhero!" << endl;
		
	}


