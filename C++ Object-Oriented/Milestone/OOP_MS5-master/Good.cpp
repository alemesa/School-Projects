//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 3 Implementation
#include <cstring>
#include <iostream>
#include "wpgeneral.h"
#include "Good.h"
using namespace std;
namespace ict {
	//Constructors
	//Empty Constructor
	Good::Good(){
		sku_[0] = '\0';
		name_ = nullptr;
		quantity_ = 0;
		price_ = 0;
		qtyNeeded_ = 0;
		taxed_ = true;
	}
	//Copy Constructor
	Good::Good(const Good &copy){
		strncpy(sku_, copy.sku_, (MAX_SKU_LEN + 1));
		int length = (strlen(copy.name_) + 1);
		name_ = new char[length];
		strncpy(name_, copy.name_, length);
		//Setting
		quantity_ = copy.quantity_;
		price_ = copy.price_;
		qtyNeeded_ = copy.qtyNeeded_;
		taxed_ = copy.taxed_;
	}
	//5 Arguments Constructor
	Good::Good(const char *sku, const char *name, double price, int qty, bool taxed){
		strncpy(sku_, sku, (MAX_SKU_LEN + 1));
		int length = (strlen(name_) + 1);
		name_ = new char[length];
		strncpy(name_, name, length);
		quantity_ = qty;
		price_ = price;
		qtyNeeded_ = 0;
		taxed_ = taxed;
	}
	//Destructor
	Good::~Good(){
		delete name_;
	}

	//Void Setters
	void Good::sku(char *sku){
		strncpy(sku_, sku, (MAX_SKU_LEN + 1));
	}
	void Good::price(double price){
		price_ = price;
	}
	void Good::name(char* name){
		name_ = new char[strlen(name) + 1];
		strncpy(name_, name, (strlen(name) + 1));
	}
	void Good::taxed(bool taxed){
		taxed_ = taxed;
	}
	void Good::quantity(int quantity){
		quantity_ = quantity;
	}
	void Good::qtyNeeded(int qtyNeeded){
		qtyNeeded_ = qtyNeeded;
	}
	//Getters
	const char *Good::sku() const{
		char const *result = this->sku_;
		return result;
	}
	double Good::price() const{
		return price_;
	}
	char const *Good::name()  const{
		return name_;
	}
	bool Good::taxed() const{
		return taxed_;
	}
	int Good::quantity() const{
		return quantity_;
	}
	int Good::qtyNeeded() const{
		return qtyNeeded_;
	}
	double Good::cost() const{
		double result = price_;
		if (taxed_) {
			result *= TAX + 1;
		}
		return result;
	}
	//Member Operators
	//Compare with the good
	bool Good::operator==(char const *second) const{
		return strcmp(sku_, second) == 0;
	}
	//Receive int and return integer
	int Good::operator+=(int qty){
		return quantity_ += qty;
	}
	//NOn member operator voerload
	//Add both values after multiplying quantity and cost of the right
	double operator+=(double &left, Good const &right){
		double sum = right.cost() * right.quantity();
		left = left + sum;
		return left;
	}
	std::ostream& operator<<(std::ostream& os, const Good& obj) {
		return obj.display(os, true);
	}
	std::istream& operator>>(std::istream& is, Good& obj) {
		return obj.conInput(is);
	}
	
}

