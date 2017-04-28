//Alejandro Mesa Suarez 
//Student #038515151
//Milestone 4 Implementation
#include<sstream>
#include<iomanip>
#include<fstream>
#include "CustomMade.h"
#include "OnShelf.h"
namespace ict {
	CustomMade::CustomMade(char rectag) :OnShelf('C'){	}
	//Getter
	const Date& CustomMade::delivery()const{
		return delivery_;
	}
	//Setter
	void CustomMade::delivery(const Date & value){
		delivery_ = value;
	}
	fstream & CustomMade::store(fstream & file, bool addNewLine) const{
		//Call the parent with arguments file and false
		OnShelf::store(file, false);
		file << "," << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
		//Add new line if true
		if (addNewLine == true) {
			file << endl;
		}
		return file;
	}
	fstream & CustomMade::load(fstream & file){
		OnShelf::load(file);
		file.ignore();
		file >> delivery_;
		Date(delivery_);
		return file;
	}
	ostream & CustomMade::display(ostream & ostr, bool linear) const{
		ostr.clear();
		// 1234|water | 1.50| 1| 5|2017/10/12
		if(err_.isClear()){
			OnShelf::display(ostr, linear);
			//linear false
			if (linear==true)
				ostr << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
			else  //linear true
				ostr << endl << "delivery date: " << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
			
		}
		else if (!err_.isClear())
			ostr << err_;
		return ostr;
	}
	istream & CustomMade::conInput(istream & istr){
		OnShelf::conInput(istr);
		cout << "delivery date (YYYY/MM/DD) : ";
		//Date Error Handling
		Date temporal;
		temporal.read(istr);
		//flag to false when an invalid entry 
		bool flag = true;
		if (temporal.errCode() == CIN_FAILED){
			err_ = "Invalid Date Entry\n\n";
			flag = false;
		}
		else if (temporal.errCode() == YEAR_ERROR){
			err_ = "Invalid Year in Date Entry\n\n";
			flag = false;
		}
		else if (temporal.errCode() == MON_ERROR){
			err_ = "Invalid Month in Date Entry\n\n";
			flag = false;
		}
		else if (temporal.errCode() == DAY_ERROR){
			err_ = "Invalid Day in Date Entry\n\n";
			flag = false;
		}
		if (!(flag))  //istr failure mode
			istr.setstate(ios::failbit);    
		else 
			delivery_ = temporal;
		return istr;
	}
}
