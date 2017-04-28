//Milestone 3
#ifndef ICT_GOOD_H__
#define ICT_GOOD_H__
#include <iostream>
#include "ReadWritable.h"
#include "wpgeneral.h"
using namespace std;
namespace ict {
	class Good :public ReadWritable {
		//Variables
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		//Constructors
		Good();
		Good(const char* sku, const char* name, double price, int qty, bool taxed = true);
		Good(const  Good &A);
		~Good();
		//Setters
		void sku(char *sku);
		void price(double price);
		void name(char* name);
		void taxed(bool taxed = false);
		void quantity(int quantity);
		void qtyNeeded(int qtyNeeded);
		//Getters
		const char *sku() const;
		double price() const;
		const char *name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		//Operator Overloads
		bool operator==(char const *second) const;
		int operator+=(int qty);
	};
	//Non-member Operator Overload
	double operator+=(double &left, Good const &right);
}
//Non-member IO
std::istream &operator>>(std::istream &is, ict::Good &obj);
std::ostream &operator<<(std::ostream &os, const ict::Good &obj);
#endif