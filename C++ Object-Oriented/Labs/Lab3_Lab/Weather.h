////////////////////////////////////////////////////////////////
// OOP244       Workshop 3: Title
// File	        w3_in_lab.cpp
// Version      1.0
// Date	        2016/10/12
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
// Description  
//              
//              
//
////////////////////////////////////////////////////////////////

// compilation safegaurds
#pragma once
#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_
/*Weather.h*/
// ict namespace
namespace ict {

	class Weather {
	
	public:
		
		char _calendar[7];
		double _high_temp;
		double _low_temp;
		void set(const char* calendar, double high_temp, double low_temp);
		void display() const;


	};


}


#endif