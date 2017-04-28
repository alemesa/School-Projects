////////////////////////////////////////////////////////////////
// OOP244       Workshop 5
// File	        contact.cpp
// Version      1.0
// Date	        2016/10/20
// Author		Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>  
#include "Contact.h"

using namespace std;

namespace ict{

	  void Contact::read(){
		cout << "Contact Name: ";
		cin.getline(name_, 41, '\n');
		cout << "Please enter " << noPN_ << " phone numbers: " << endl;
		for (int i = 0; i < noPN_; i++){
		  cout << i + 1 << ": ";
		  phoneNumber_[i].read();
		}
	  }

	  bool Contact::isEmpty()const{
		return phoneNumber_ == nullptr;
	  }

	  void Contact::setEmpty(){
		name_[0] = 0;
		noPN_ = 0;
		phoneNumber_ = nullptr;
	  }

	  //Implementation of Constructor , with empty state
	  Contact::Contact() {
		  setEmpty();
	  }

	  //Implementation of Constructor with 2 arguments
	  Contact::Contact(const char* name, int num) {
		phoneNumber_ = new PhoneNumber[num];
		noPN_ = num;
		strncpy(name_, name, 40);
		name_[40] = '\0'; //null terminator
	  
	  }

	  //Implementation of display function
	  void Contact::display() const {

		  cout << name_ << endl;

		  if (noPN_ > 0) {

			  for (int i = 0; i < noPN_; i++) {
				  phoneNumber_[i].display();
			  }
		  }

		  cout << "----------------------------------------" << endl;



	  }


	  //Implementation of Destructor
	  Contact::~Contact() {
	  
		  delete[] phoneNumber_;
	  }

	  

}