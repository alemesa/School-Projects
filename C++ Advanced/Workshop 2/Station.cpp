/*
OOP345
Workshop 2
Title    : Compound Types
Date     : 03/01/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Station.h"

using namespace std;

namespace w2 {

  Station::Station() {

    _stationName = "";
    passes[STUDENT_PASS] = 0;
    passes[ADULT_PASS] = 0;
  }

  void Station::set(const string & stationName, unsigned studentPass, unsigned adultPass) {

    _stationName = stationName;
    passes[STUDENT_PASS] = studentPass;
    passes[ADULT_PASS] = adultPass;
  }

  void Station::update(PassType pt, int qty) {

    passes[pt] = passes[pt] + qty;
  }

  unsigned Station::inStock(PassType pt) const {

    return passes[pt];

  }

  const string & Station::getName() const {

    return _stationName;

  }

  Station::~Station() {
  }

}
