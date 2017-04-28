////////////////////////////////////////////////////////////////
// OOP244       Workshop 3: Dynamic Memory
// File	        w3_at_home.cpp
// Version      1.0
// Date	        2016/10/13
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
// Description  
//              
//              
//
////////////////////////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "Weather.h"
using namespace std;
using namespace ict;

double findLow(const char* date, const Weather* data, int dataSize);


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

  char query[7];
  cout << endl << "Enter the date you are looking for: ";
  
  
  cin.ignore();
	  
  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.

  cin.getline(query, 7, '\n');
  double low = findLow(query, weather, n);
  cout << "Low temperature: " << low << endl;
  


  // deallocate dynamic memory here
  delete[] weather;
  weather = nullptr;

  return 0;
}

double findLow(const char* date, const Weather* data, int dataSize) {

	const char* temp;
	
	double result = 0.0;

	for (int i = 0; i < dataSize; i++) {

		temp = data[i].date();

		if (strcmp(temp,date)==0) {

			result = data[i].low();
			break;

		}

		

	}

	return result;
}

