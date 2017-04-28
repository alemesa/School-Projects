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
#include "Product.h"
#include <vector>

namespace w7 {
    class Sale {
        std::vector<iProduct*> vecOfProduct;
    public:
        Sale(const char* filename) {
            std::ifstream is(filename);
            if (is.is_open()) {
                iProduct* p;
                while (p = readProduct(is)) {
                    vecOfProduct.push_back(p);
                }
                is.close();
            }
            else
                throw std::string("Cannot open a file") + filename + "\n";
        }


        void display(std::ostream& os) const {
            os << "Product No   Cost  Taxable\n";
            double total = 0;
            for(auto e : vecOfProduct) {
                total += e->getCharge();
                std::cout << *e << "\n";
            }
            std::cout << "\nTotal: " << total;
        }
    };
}
