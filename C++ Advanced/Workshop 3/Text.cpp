/*
OOP345
Workshop 3
Title    : Copy and Move Semantics
Date     : 03/06/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include <fstream>
#include <iostream>
#include <string>

#include "Text.h"

using namespace std;

namespace w3 {

    Text::Text(char * filename) : count(0), linerow(nullptr) {
        fstream is(filename, ios::in);
        if (is.is_open()) {
            string line;
            while (getline(is, line)) {
                count++;
            }
            cout << "File " << filename << " has " << count << " lines." << endl;

            linerow = new string[count];
            //Reset File
            is.clear();
            //Go to the beginning
            is.seekg(0);

            for (size_t i = 0; i < count; i++) {
                getline(is, linerow[i]);
            }
            is.close();
        }
        else {
            cerr << "Cannot open filename:" << filename << endl;
            exit(1);
        }
    }


    Text& Text::operator = (const Text& rhs) {

        if (this != &rhs) {

            delete[] linerow;
            count = rhs.count;
            linerow = new string[count];

            for (size_t i = 0; i < count; i++) {
                linerow[i] = rhs.linerow[i];
            }
        }
        return *this;
    }

    Text::Text(Text&& rhs) : count(0), linerow(nullptr) {
        if (this != &rhs)
            *this = move(rhs);
    }
    Text& Text::operator = (Text&& rhs) {

        if (this != &rhs) {
            delete[] linerow;
            count = rhs.count;
            linerow = rhs.linerow;
            rhs.count = 0;
            rhs.linerow = nullptr;
        }
        return *this;

    }

    Text::Text(const Text& rhs) : count(0), linerow(nullptr){
        *this = rhs;
        }
}
