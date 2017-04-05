/*
OOP345
Workshop 5
Title    : Containers
Date     : 03/15/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include <iostream>
#include <string>
#include "Message.h"
using namespace std;

namespace w5 {

	Message::Message(std::ifstream& input, char delimiter)
	{
		name.clear();
		reply.clear();
		message.clear();

		std::string line;
		getline(input, line);

		int index = 0;
		while (index < line.size() && line[index] != ' '){
			name += line[index];
			index++;

		}
		index++;
		if (index < line.size() && line[index] == '@'){
			index++;
			while (index < line.size() && line[index] != ' '){
				reply += line[index];
				index++;
			}

		}

		while (index < line.size()){
			message += line[index];
			index++;
		}
	}

	bool Message::empty() const{
		return message.empty();
	}

	void Message::display(std::ostream& os) const
	{
		os << "Message\n";
		os << " User  : " << name << "\n";

		if (reply.empty()==false)
		{
			os << " Reply : " << reply << "\n";
			os << " Tweet :" << message << "\n";
		}
		else {
			os << " Tweet : " << message << "\n";
			os << "\n";
		}
	}
}
