#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict {
	// member functions' (methods') definition go here
	void AccountNumber::name(const char name[]) {


		strcpy(_name, name);

	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber) {


		_validAccNumber = false;

		if (bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE && branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE && accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO) {


			_validAccNumber = true; 
			_bankCode = bankCode;
			_branchCode = branchCode;
			_accountNumber = accountNumber;

		}


	}

	void AccountNumber::display() const {

		if (isValid()) {

			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber << endl;

		}
		else {

			cout << _name << " does not have a valid account number." << endl;

		}

	}

	bool AccountNumber::isValid() const {

		return _validAccNumber;


	}




}