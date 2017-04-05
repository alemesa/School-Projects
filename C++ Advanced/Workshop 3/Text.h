/*
OOP345
Workshop 3
Title    : Copy and Move Semantics
Date     : 03/06/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w3 {
    class Text {
        size_t count;
        string* linerow;
    public:
        size_t size() const { return count; }
        Text(char * filename);
        Text() : count(0), linerow(nullptr) {  }
        Text(const Text& rhs);
        Text& operator = (const Text& rhs);
        Text(Text&& rhs);
        Text& operator = (Text&& rhs);
        ~Text() { delete[] linerow; }
    };
}
