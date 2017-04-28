//Milestone 2
#include "Error.h"
#include <cstring>
#include<iostream>
#include "wpgeneral.h"
using namespace std;
namespace ict {
	//Empty constructor
	Error::Error() {
		//Set to null
		message_ = nullptr;
	}
	Error::Error(const char* Error){
		//Set to null and use the setter
		message_ = nullptr;
		message(Error);
	}
	Error &Error :: operator=(const char* Error){
		message(Error);										//set message			
		delete[] message_;									//deallocationg
		int length = strlen(Error) + 1;						//allocating with +1 len
		message_ = new char[length];				
		strncpy(message_, Error, (length));					//copy error
		return *this;										//return *this
	}
	//De-Allocate Memory
	Error:: ~Error(){
		delete[] message_;
	}
	//De-Allocate Memory + null message
	void  Error::clear(){
		delete[] message_;
		message_ = nullptr;
	}
	//Check if message is null
	bool Error::isClear()const{
		return message_ == nullptr;
	}
	void Error::message(const char* value){
		delete[] message_;									//deallocate memory
		int length = strlen(value) + 1;						//allocating with +1 len
		message_ = new char[length];
		strncpy(message_, value, (length));					//copy value	
	}
	//return address of message
	const char* Error::message() const{
		return message_;
	}
	//IO Implementation
	ostream& operator<<(ostream& ostr, const Error& obj){
		if (obj.isClear())
			ostr << "";
		else
			ostr << obj.message();
		return ostr;
	}

}
