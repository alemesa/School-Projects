//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 2 Implementation
#ifndef SICT_ERROR_H__
#define SICT_ERROR_H__
#include <iostream>
using namespace std;
namespace ict {
	class Error {
	//private data memeber
		char *message_;
	public:
		//Constructors
		//Empty
		Error();
		//Two arguments
		Error(const char* Error);
		//Copy constructor
		Error(const Error& em) = delete;

		//Operator Overloads
		Error& operator=(const Error& em) = delete;
		Error& operator=(const char* Error);

		//Virtual
		~Error();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message() const;             
	};
	//Helper Operator
	std::ostream &operator<<(ostream& ostr, const Error& obj);
}
#endif
