//Milestone 4
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
		OnShelf::store(file, false);
		file << "," << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
		if (addNewLine)
			file << endl;
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

			if (linear)
				ostr << delivery_.year_ << "/" << delivery_.mon_ << "/" << delivery_.day_;
			else
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
		Date tempData;
		tempData.read(istr);
		//flag to false when an invalid entry 
		bool flag = true;
		if (tempData.errCode() == CIN_FAILED){
			err_ = "Invalid Date Entry";
			flag = false;
		}
		else if (tempData.errCode() == YEAR_ERROR){
			err_ = "Invalid Year in Date Entry";
			flag = false;
		}
		else if (tempData.errCode() == MON_ERROR){
			err_ = "Invalid Month in Date Entry";
			flag = false;
		}
		else if (tempData.errCode() == DAY_ERROR){
			err_ = "Invalid Day in Date Entry";
			flag = false;
		}
		if (!(flag))  
			istr.setstate(ios::failbit);    //Set the istr to failure mode
		else 
			delivery_ = tempData;
		return istr;
	}
}
