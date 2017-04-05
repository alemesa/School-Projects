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
#include <fstream>
#include <iostream>

using namespace std;

namespace w5 {
	class Message {
		string name;
		string reply;
		string message;

		public:
			Message() {}
			Message(std::ifstream& input, char delimiter);
			bool empty() const;
			void display(std::ostream&) const;
	};
}
