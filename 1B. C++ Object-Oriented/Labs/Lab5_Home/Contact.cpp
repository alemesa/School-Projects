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

	  //Implementation of Copy Constructor
	  Contact::Contact(const Contact &new_) {
		  
		  noPN_ = new_.noPN_;   //make a copy
		  
		  if (new_.isEmpty()) {  //set current object to empty
			  
			  this->setEmpty();

		  }
		  else {
			  Contact(new_.name_, new_.noPN_);
			  //Allocate Dynamic Array with exact same size
			  phoneNumber_ = new PhoneNumber[new_.noPN_];
			  //Set each phone number ot the current object
			  for (int i = 0; i < new_.noPN_; i++) {
				  phoneNumber_[i] = new_.phoneNumber_[i];
			  }
		  }
		  
	  }


	  //Implementation of Assignment Operator
	  Contact& Contact::operator=(const Contact& C) {
		  
		  
		  //Contact being set to itself
		  if (this == &C) {
			  return *this;
		  }
		  //Contact is not being set to itself
		  else {
		  
			  delete[] phoneNumber_;
			  if (C.isEmpty()) {
				  this->setEmpty();

			  }
			  else {
				  Contact(C.name_, C.noPN_);
				  phoneNumber_ = new PhoneNumber[C.noPN_];
				  for (int i = 0; i < C.noPN_; i++) {
					  phoneNumber_[i] = C.phoneNumber_[i];
				  }
			  }
			  return *this;
		  }
		  
		  
		  }
			  
			  
				
		 
	  }
	  

