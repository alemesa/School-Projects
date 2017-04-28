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

using namespace std;

namespace w2 {

  enum PassType {
    STUDENT_PASS,
    ADULT_PASS,
    PASS_COUNT
  };

  class Station {

    private:

    string _stationName;
    int passes[PASS_COUNT];

    public:

    Station();
    void set(const string & stationName, unsigned studentPass, unsigned adultPass);
    unsigned inStock(PassType) const;
    void update(PassType pt, int qty);
    const string & getName() const;
    ~Station();

  };

}
