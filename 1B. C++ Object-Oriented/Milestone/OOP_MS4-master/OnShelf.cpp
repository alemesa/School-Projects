//Milestone 4
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include "Error.h"
#include "OnShelf.h"
#include "CustomMade.h"
#include "ReadWritable.h"
using namespace std;
namespace ict {
	//Constructor
	OnShelf::OnShelf(char filetag_){
		recTag_ = filetag_;
	}
	//Public member functions
	fstream & OnShelf::store(fstream & file, bool addNewLine) const{
		//------ >  O,1234,box,123.45,1,1,5<Newline>
		file << recTag_ << ",";
		file << sku() << "," << name() << "," << price() << "," << int(taxed()) << "," << quantity() << "," << qtyNeeded();
		if (addNewLine == true)
			file << endl;
		return file;
	}
	fstream & OnShelf::load(fstream & file){
		//Declaring variables
		int const length = MAX_SKU_LEN + 1;
		char extraSKU[length];
		char extraName[1000];
		bool extraTaxed;
		double extraPrice;
		int extraQuantity;
		int extraQtyNeeded;

		//Getting lines
		file.getline(extraSKU, length, ',');
		sku(extraSKU);
		file.getline(extraName, 1000, ',');
		name(extraName);
		file >> extraPrice;
		price(extraPrice);
		file.ignore();
		file >> extraTaxed;
		taxed(bool(extraTaxed));
		file.ignore();
		file >> extraQuantity;
		quantity(extraQuantity);
		file.ignore();
		file >> extraQtyNeeded;
		qtyNeeded(extraQtyNeeded);
		return file;
		
	}
	ostream& OnShelf::display(ostream& os, bool linear)const{
		if (err_.isClear()) {
			int const length = 20;
			char tempName[length+1];
			strncpy(tempName, name(), length);
			tempName[length] = '\0';
			char tax_string;
			if (linear == false) {
				os << "Sku: " << sku() << endl << "Name: " << name() << endl << "Price: " << fixed << setprecision(2) << price() << endl << "Price after tax: ";
				if (!taxed())
					os << "N/A";
				else
					os << fixed << setprecision(2) << cost();
				os << endl << "Quantity On Hand: " << quantity() << endl << "Quantity Needed: " << qtyNeeded();	
			}
			else {
				if (taxed() == true) {
					tax_string = 't';
				}
				else
					tax_string = ' ';
				os << sku() << "|" << setw(20) << left << name() << right << "|" << setw(7) << setprecision(2) << fixed << cost() << "| " << tax_string << " |";
				os.setf(ios::right);
				os << setw(4) << quantity() << "|" << setw(4) << qtyNeeded() << "|";
			}
		}
		else {
			os << err_;
		}
		return os;
	}
	std::istream& OnShelf::conInput(std::istream& is){
		char sku2[100];
		char name2[1000];
		double price2;
		char taxed2;
		int qty_hand2;
		int qty_need;

		//If fail passes
		if (is.fail() == false) {
			err_.clear();
			cout << "Sku: ";
			is >> sku2;
			//Check SKU
			if (is.fail() == false) {
				sku(sku2);
			}
			cout << "Name: ";
			is >> name2;
			//Check Name
			if (is.fail() == false) {
				name(name2);
			}
			cout << "Price: ";
			is >> price2;
			//Check Price
			if (is.fail()) {
				err_.message("Invalid Price Entry");
			}
			else {
				price(price2);
			}
			//Check Taxed
			if (err_.isClear()) {
				cout << "Taxed: ";
				is >> taxed2;
				if (taxed2 == 'Y' || taxed2 == 'y') {
					taxed(true);
				}
				else if (taxed2 == 'N' || taxed2 == 'n') {
					taxed(false);
				}
				else {
					err_.message("Only (Y)es or (N)o are acceptable");
					is.setstate(std::ios::failbit);
				}
			}
			//Check Quantity on Hand
			if (err_.isClear()) {
				cout << "Quantity On hand: ";
				is >> qty_hand2;
				if (is.fail()) {
					err_.message("Invalid Quantity Entry");
				}
				else {
					quantity(qty_hand2);
				}
			}
			//Check Quantity Needed
			if (err_.isClear()) {
				cout << "Quantity Needed: ";
				is >> qty_need;
				if (is.fail()) {
					err_.message("Invalid Quantity Needed Entry");
				}
				else {
					qtyNeeded(qty_need);
				}
			}
		}
		//Return value
		return is;
	}
}