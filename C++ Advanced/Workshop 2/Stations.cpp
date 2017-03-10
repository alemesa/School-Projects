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
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>

#include "Stations.h"
#include "Station.h"

using namespace std;

namespace w2 {

  Stations::Stations(char * filename) {

    fstream is(filename);

    //is.open(filename, ios::in);

    if (is.is_open()==false) {

      cerr << "Not possible to open the file: " << filename << endl;

    }
    string line;

    is >> stacount;

    is.ignore(2, ';');

    cout << "Station Count = " << stacount << endl;


    string stationName;
    stationActual = new Station[stacount];

    unsigned stupass = 0, adultpass = 0;

    for (size_t i = 0; i < stacount; i++) {

      getline(is, stationName, ';');
      is >> stupass;
      is >> adultpass;

      stationActual[i].set(stationName, stupass, adultpass);
    }

    is.close();
  }

  void Stations::update() const {

    cout << "Passes Sold :" << endl << "-------------";
    for (int i = 0; i < stacount; i++) {
      int student, adult;
      cout << stationActual[i].getName();
      cout << endl;
      cout << "Student Passes sold : ";
      cin >> student;
      cout << "Adult   Passes sold : ";
      cin >> adult;

      stationActual[i].update(STUDENT_PASS, -student);
      stationActual[i].update(ADULT_PASS, -adult);
    }

  }
  void Stations::restock() const {

    cout << "Passes Added :" << endl << "--------------" << endl;

    for (int i = 0; i < stacount; i++) {

      int s, a;

      cout << stationActual[i].getName() << endl;
      cout << "Student Passes added : ";
      cin >> s;
      cout << "Adult   Passes added : ";
      cin >> a;
      stationActual[i].update(STUDENT_PASS, s);
      stationActual[i].update(ADULT_PASS, a);
    }
  }
  void Stations::report() const {

    cout << "Passes in Stock : Student Adult" << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i < stacount; i++) {

      cout << left << setw(19) << stationActual[i].getName()
      << setw(6) << stationActual[i].inStock(STUDENT_PASS)
      << setw(6) << stationActual[i].inStock(ADULT_PASS)
      << endl;
    }
  }

  Stations::~Stations() {

    if (stationActual) {
      delete[] stationActual;
    }
  }

}
