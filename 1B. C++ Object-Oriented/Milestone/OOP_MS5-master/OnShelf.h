//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 4 Implementation
#ifndef ICT_ONSHELF_H__
#define ICT_ONSHELF_H__
#include "Good.h"
#include "Error.h"
namespace ict {
	//Derived Class
	class OnShelf : public Good {
	private:
		char recTag_;
	protected:
		Error err_;
	public:
		//Constructor
		OnShelf(char filetag_ = 'O');
		//Public member functions
		fstream& store(fstream & file, bool addNewLine = true) const;
		fstream& load(fstream& file);
		ostream& display(ostream& os, bool linear)const;
		istream& conInput(istream& is);
	};
}
#endif