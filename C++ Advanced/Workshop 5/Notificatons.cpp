/*
OOP345
Workshop 5
Title    : Containers
Date     : 03/15/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include "Notifications.h"

namespace w5{

    Notifications::Notifications(const Notifications& rhs){
		count = rhs.count;

		for (int i = 0; i < count; i++){
			ptrMessages[i] = rhs.ptrMessages[i];
		}
	}

    //Copy Assignment Operator
    	Notifications& Notifications::operator=(const Notifications& rhs){
		if (this != &rhs) {
			if (ptrMessages == nullptr){
				ptrMessages = new Message[CAPACITY];
			}
			count = rhs.count;

			for (int i = 0; i < count; i++){
				ptrMessages[i] = rhs.ptrMessages[i];
			}
		}
		return *this;
	}

    //Move Constructor
    Notifications::Notifications(Notifications&& rhs){
		rhs.count = 0;
		rhs.ptrMessages = nullptr;
	}

    //Move Assignment Operator
    Notifications&& Notifications::operator=(Notifications&& rhs){
		if (this != &rhs){
			delete[] ptrMessages;
			count = rhs.count;
			ptrMessages = rhs.ptrMessages;
			rhs.count = 0;
			rhs.ptrMessages = nullptr;
		}

		return std::move(*this);
	}

    //Ostream insertion
    void Notifications::display(std::ostream& os) const{
		for (int i = 0; i < count; i++){
			ptrMessages[i].display(os);
		}
	}

	void Notifications::operator+=(const Message& message){
		if (count < CAPACITY){
			ptrMessages[count] = message;
			count++;
		}
	}

    //Destructor
    Notifications::~Notifications(){
		delete[] ptrMessages;
	}

}
