//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 1 Implementation
#ifndef ICT_DATE_H__
#define ICT_DATE_H__
#define NO_ERROR   0  
#define CIN_FAILED 1  
#define YEAR_ERROR 2
#define MON_ERROR  3  
#define DAY_ERROR  4  
#include <iostream>
namespace ict {
	class Date {
		//Private Functions
	private:
		int value() const;             //Provided
		void errCode(int errorCode);
	public:
		//Variables
		int year_;
		int mon_;
		int day_;
		int readErrorCode_;

		int mdays() const;             //Provided

		//Constructors
		Date();
		Date(int year, int mon, int day);

		//Public Member Functions 
		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;

		//Accesor or getter member functions
		int errCode();
		bool bad()const;

		//IO Functions
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
	};
	//IO Helpers
	std::istream&  operator>>(std::istream& istr, Date& obj);
	std::ostream&  operator<<(std::ostream& ostr, const Date& obj);
}
#endif