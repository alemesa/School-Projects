/*
OOP345
Workshop 5
Title    : Containers
Date     : 03/15/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#pragma once
#include <iostream>
#include <string>
#include "Message.h"

namespace w5 {
	static const int CAPACITY = 10;

	class Notifications {
	    private:
			Message* ptrMessages;
			size_t count;

		public:
			Notifications() : count(0), ptrMessages(new Message[CAPACITY]) {}
			Notifications(const Notifications& rhs);
			Notifications& operator=(const Notifications& rhs);
			Notifications(Notifications&& rhs);
			Notifications&& operator=(Notifications&& rhs);
			~Notifications();
			void operator+=(const Message& message);
			void display(std::ostream& os) const;
	};

}
