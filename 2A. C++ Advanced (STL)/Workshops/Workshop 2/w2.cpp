/*
OOP345
Workshop 2
Title    : Compound Types
Date     : 03/01/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

 // Workshop 2 - unsigned int, Enumerations, String Class and File I/O
 // w2.cpp

#include <iostream>
#include "Stations.h"

int main(int argc, char* argv[]) {
    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\nIncorrect number of arguments\n";
        return 1;
    }
    w2::Stations stations(argv[1]);
    stations.update();
    stations.restock();
    stations.report();
    return 0;
}
