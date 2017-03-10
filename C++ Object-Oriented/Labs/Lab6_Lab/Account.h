////////////////////////////////////////////////////////////////
// OOP244       Workshop 6
// File	        in_lab6.cpp
// Version      1.0
// Date	        2016/October/30
// Author		Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>
using namespace std;
namespace ict{
   class Account{
      char name_[41];
      double balance_;
   public:
      void display(bool gotoNewline = true)const;
      Account();
      Account(double balance);
      Account(const char name[], double balance = 0.0);
	  Account& operator+=(const Account& src);
	  Account& operator=(const char src[40]);
	
	  friend Account operator+(const Account& first, const Account& second);
	  friend ostream& operator<<(ostream& ostream, const Account& src);
   };
   
   

};

#endif
