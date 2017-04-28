////////////////////////////////////////////////////////////////
// OOP244       Workshop 4: Constructors
// File	        w4_in_lab.cpp
// Version      1.0
// Date	        2016/10/14
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////



#include "Enrollment.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS   //Visual Studio keep telling me to use strcpy_ instead

using namespace std;
using namespace ict;

namespace ict {
	Enrollment::Enrollment()
	{
		setEmpty();
	}


	Enrollment::Enrollment(const char * name, const char * code, int year, int semester, int slot)
	{
		set(name, code, year, semester, slot);
	}


	
		bool Enrollment::isValid()const {
			return _name && _name[0];
		}

	
	void Enrollment::setEmpty() {
		_name[0] = 0;
		_code[0] = 0;
		_year = 0;
		_semester = 0;
		_slot = 0;
		_enrolled = false;
	}

	
	bool Enrollment::isEnrolled() const {
		return _enrolled;
	}

	void Enrollment::display(bool nameOnly)const {
		if (isValid()) {
			cout << _name;
			if (!nameOnly) {
				cout << endl << _code << ", Year: " << _year << " semester: " << _semester << " Slot: " << _slot << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else {
			cout << "Invalid enrollment!" << endl;
		}
	}


	void Enrollment::set(const char* nameNew, const char* codeNew, int year, int semester, int time, bool enrolled) {
		if (nameNew != NULL && nameNew[0] != 0 && codeNew != NULL && codeNew[0] != 0 && year >= 2015 && semester > 0 && semester < 4 && time >0 && time < 6) {
			
				strcpy(_name, nameNew);
				strcpy(_code, codeNew);
				_year = year;
				_semester = semester;
				_slot = time;
				_enrolled = enrolled;
		}
		else {
			this->setEmpty();
		}
	}

	bool Enrollment::hasConflict(const Enrollment &other)const {

		bool result;

		if (isValid() && other.isValid() && _year == other._year && _semester == other._semester && _slot == other._slot) {
			result = true;
			
		}
		else {
			result = false;
		}

		return result;
	}
}



