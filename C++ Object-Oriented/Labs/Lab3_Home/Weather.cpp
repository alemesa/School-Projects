////////////////////////////////////////////////////////////////
// OOP244       Workshop 3: Dynamic Memory
// File	        w3_at_home.cpp
// Version      1.0
// Date	        2016/10/13
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
// Description  
//              
//              
//
////////////////////////////////////////////////////////////////


/*Weather.cpp*/
//  includes go here
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Weather.h"

// ict namespace
namespace ict {
	// set
	
	void Weather::set(const char* calendar, double high_temp, double low_temp) {
		
		strncpy(_calendar, calendar, 7);
		_high_temp = high_temp;
		_low_temp = low_temp;
	   
	}

	// display
	void Weather::display() const {
	
		cout << setw(10) << left << setfill('_') << _calendar
			<< setw(6) << right << setfill('_') << setprecision(1) << fixed << _high_temp
			<< setw(6) << right << setfill('_') << setprecision(1) << fixed << _low_temp
			<< endl;
	}

	const char* Weather::date() const {
	
		return _calendar;

	}

	double Weather::low() const {
	
		return _low_temp;
	
	}


	
}