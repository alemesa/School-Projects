#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "wpgeneral.h"
using namespace std;
namespace ict {
	void Date::errCode(int errorCode){
		readErrorCode_ = errorCode;
	}
	//Provided
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}
	//Provided
	int Date::mdays()const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
	//Empty Constructor
	Date::Date(){
		year_ = 0;
		day_ = 0;
		mon_ = 0;
		readErrorCode_ = NO_ERROR;
	}
	//Constructor 3 values
	Date::Date(int year, int mon, int day){
		year_ = year;
		mon_ = mon;
		day_ = day;
		readErrorCode_ = NO_ERROR;
	}
	//Getter
	int Date::errCode(){
		return readErrorCode_;
	}
	//Setter
	bool  Date::bad()const{
		bool result = false;
		if (readErrorCode_ != NO_ERROR)
			result = true;
		return result;
	}

	std::istream& Date::read(std::istream& istr = std::cin){
		istr >> year_;
		//istream fail
		if (istr.get() != '/') {
			readErrorCode_ = CIN_FAILED;
			return istr;
		}
		istr >> mon_;
		if (istr.get() != '/') {
			readErrorCode_ = CIN_FAILED;
			return istr;
		}
		istr >> day_;
		//year validation
		if (year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
		}
		//month validation
		else if (mon_ < 1 || mon_ > 12){
			readErrorCode_ = MON_ERROR;
		}
		//day validation
		else if (day_ < 1 || day_ > mdays()){
			readErrorCode_ = DAY_ERROR;
		}
		//no error
		else {
			readErrorCode_ = NO_ERROR;
		}
			return istr;
	}
	std::ostream& Date::write(std::ostream& ostr = std::cout)const
	{
		//Fromatting loop to add decimals
		ostr << year_;
		if (mon_ >= 10) {
			ostr << "/" << mon_;
		}
		else {
			ostr << setw(2) << setfill('0') << "/" << mon_;
		}
			
		if (day_ >= 10) {
			ostr << "/" << day_;
		}
		else {
			ostr << setw(2) << setfill('0') << "/" << day_;
		}
			
		return ostr;
	}
	//IO
	std::ostream&  operator<<(std::ostream& ostr, const Date& obj)
	{
		obj.write(ostr);
		return ostr;
	}
	std::istream& operator >> (std::istream& istr, Date& obj)
	{
		obj.read(istr);
		return istr;
	}

	//Operator overloads
	
	bool Date::operator==(const Date& D)const { return this->value() == D.value(); }
	bool Date::operator!=(const Date& D)const { return this->value() != D.value(); }
	bool Date::operator< (const Date& D)const { return this->value() <  D.value(); }
	bool Date::operator> (const Date& D)const { return this->value() >  D.value(); }
	bool Date::operator<=(const Date& D)const { return this->value() <= D.value(); }
	bool Date::operator>=(const Date& D)const { return this->value() >= D.value(); }
	
}