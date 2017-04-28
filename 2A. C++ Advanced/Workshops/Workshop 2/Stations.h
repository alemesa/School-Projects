/*
OOP345
Workshop 2
Title    : Compound Types
Date     : 03/01/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#pragma once
#include <string>
#include <fstream>

#include "Station.h"

using namespace std;

namespace w2 {

    class Stations{

    private:

        char* _filename;
        int stacount;
		string name;
        Station* stationActual;

    public:

        Stations(char* filename);
		~Stations();
        void update() const;
        void restock() const;
        void report() const;
       };
}
