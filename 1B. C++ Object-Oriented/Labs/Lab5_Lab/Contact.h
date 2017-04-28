////////////////////////////////////////////////////////////////
// OOP244       Workshop 5
// File	        contact.h
// Version      1.0
// Date	        2016/10/20
// Author		Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef ICT_CONTACT_H
#define ICT_CONTACT_H
#include "PhoneNumber.h"


namespace ict {
	class Contact {
		
		PhoneNumber* phoneNumber_;
		char name_[41]; //One more
		int noPN_;
		void setEmpty();

	public:
		Contact(); //Empty constructor
		Contact(const char* name, int num);  //Constructor 2 arguments
		~Contact();       //Destructor
		void read();		
		bool isEmpty()const;
		void display() const;  //Display function
	};

}
#endif