////////////////////////////////////////////////////////////////
// OOP244       Workshop #: Title
// File	        filename.cpp
// Version      1.0
// Date	        year/month/day
// Author	Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
// Description  
//              
//              
//
////////////////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"
using namespace std;
using namespace ict;
int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  // initialize the weather pointer here
  Weather* weather = nullptr;
  //
  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  weather = new Weather[n];

  // allocate dynamic memory here

  //
  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;

	cout << "Enter date: ";
	cin >> date_description;
	cout << "Enter high: ";
	cin >> high;
	cout << "Enter low : ";
	cin >> low;
    // ... add code to accept the user input
    // for the weather array
	weather[i].set(date_description, high, low);
  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++){
	  
    weather[i].display();
  }

  // deallocate dynamic memory here
  delete[] weather;
  weather = nullptr;

  return 0;
}
