/*
OOP345
Workshop 7
Title    : STL Containers
Date     : 03/23/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/


#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

namespace w7 {
    enum TaxType_e {NO_TAX, HST, PST};

    class iProduct {
		public:
			virtual double getCharge() const = 0;
			virtual void display(std::ostream&) const = 0;
    };

    class Product : public iProduct {

			int code;
			double price;

		public:

			Product(int c, double p) : code(c), price(p) { }

			double getCharge() const {
				return price;
			}

			void display (std::ostream& os) const{
				os << std::setw(10) << code << "   "
                   << std::setprecision(2) << std::fixed
                   << getCharge();
			}
    };


    class ProductTaxible : public Product {
			int code;
			double price;
			TaxType_e type;
		public:
			ProductTaxible(int c, double p, TaxType_e t) : Product(c,p), type(t) {}

			double getCharge() const {
				double  p;
				if(type == HST)
                    return Product::getCharge() * 1.13;
				else if(type == PST)
                    return Product::getCharge() * 1.08;
			}

			void display (std::ostream& os) const{
			   Product::display(os);
			   if(type == HST)
                    std::cout << " HST";
				else if(type == PST)
                    std::cout << " PST";
			}
    };


    std::ostream& operator<<(std::ostream& os, const iProduct& ref) {
        ref.display(os);
        return os;
    }

    iProduct* readProduct(std::ifstream& is) {
        TaxType_e tc;

        iProduct* returnValue = nullptr;
        std::string s;


		    int idx = 0;
            int code = 0;
			double price = 0;
			double scale = 1;


        if ( getline( is, s) ) {

            auto cr = s.find("\r");
            if(cr != std::string::npos) {
                std::cout << "found a CR at offset " << cr << "\n";
                s.erase( s.begin() + cr);
            }

            while( idx < s.size() && isdigit(s[idx]) ) {
                code = 10 * code + (s[idx] - '0');
                idx++;
            }

            while( idx < s.size() && isspace(s[idx]) ) {
                    idx++;
            }

            while( idx < s.size() && isdigit(s[idx]) ) {
                price = 10 * price + (s[idx] - '0');
                idx++;
            }

            if (idx < s.size() && s[idx] == '.') {
                idx++;
            }

            while( idx < s.size() && isdigit(s[idx]) ) {
                price = 10 * price + (s[idx] - '0');
                idx++;
                scale *= 0.1;
            }
            price *= scale;


            while( idx < s.size() && isspace(s[idx]) ) {
                    idx++;
            }

            if(idx < s.size()) {
				if(s[idx] == 'H'){
                    tc = HST;
				}
				else if(s[idx] == 'P'){
                    tc = PST;
				}
				else{
                    throw std::string("Unknown tax code '") + s[idx];
				}
            }
            else {
                tc = NO_TAX;
            }

            if(tc == HST){
                returnValue = new ProductTaxible(code,price,tc);
            }
            else if(tc == PST){
                returnValue = new ProductTaxible(code,price,tc);
            }
            else{
                returnValue = new Product(code, price);
            }

        }

        return returnValue;
    }

}
