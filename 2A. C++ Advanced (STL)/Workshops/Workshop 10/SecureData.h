/*
OOP345
Workshop 10
Title    : Multi-Threading
Date     : 04/03/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include <iostream>

namespace w10 {

	class Cryptor {
	public:
		char operator()(char in, char key) const { return in ^ key; }
	};
	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(std::ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};
	std::ostream& operator<<(std::ostream&, const SecureData&);
}

