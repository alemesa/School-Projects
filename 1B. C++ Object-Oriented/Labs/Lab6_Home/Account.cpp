////////////////////////////////////////////////////////////////
// OOP244       Workshop 6
// File	        at_home.cpp
// Version      1.0
// Date	        2016/October/30
// Author		Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

namespace ict {

	//Given
	void Account::display(bool gotoNewline)const {
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}

	//Default
	Account::Account() {
		name_[0] = 0;
		balance_ = 0;
	}
	//Default
	Account::Account(double balance) {
		name_[0] = 0;
		balance_ = balance;
	}
	//Default
	Account::Account(const char name[], double balance) {
		strcpy(name_, name);
		balance_ = balance;
	}
	//Adds the balance of C to B and returns the reference of B,
	//so A will be to B afterwards.
	Account& Account::operator+=(const Account& src) {
		this->balance_ += src.balance_;
		return *this;
	}
	//Sets the name of B to “new name” and returns 
	//the reference of B.
	Account& Account::operator=(const char src[40]) {
		strncpy(name_, src, 41);
		return *this;
	}
	//this operator returns an account with an empty name 
	//and a balance of the sum of two balances of B and C.
	Account operator+(const Account& first, const Account& second) {
		double sum = first.giveBal() + second.giveBal();
		return Account("", sum);
	}
	//Overload operator<<  so the following is possible
	ostream& operator<<(ostream& ostream, const Account& src) {
		src.display(false);
		return ostream;
	}


	//AT-HOME Portion
	//The Balance or A should be added to the value of “e”
	//and then the modified value returned
	double operator+=(double& balance, const Account& src) {
		balance += src.giveBal();
		return balance;
	}
	double Account::giveBal() const{
		return balance_;
	}

}