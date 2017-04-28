//Milestone 4
#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__
#include "OnShelf.h"
#include "Date.h"
#include "Error.h"
namespace ict {
	//Derived class
	class CustomMade :public OnShelf {
	private:
		Date delivery_;
	public:
		//Constructor
		CustomMade(char rectag = 'C');
		//Setters and getters
		const Date& delivery()const;
		void delivery(const Date&value);
		//Virtual Methods
		fstream& store(fstream & file, bool addNewLine = true) const;
		fstream& load(fstream& file);
		ostream& display(ostream& ostr, bool linear)const;
		istream& conInput(istream& istr);
	};
}
#endif