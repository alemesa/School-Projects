/*
OOP345
Workshop 6
Title    : Lambda Expressions
Date     : 03/21/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Grades{
	std::string* studentID;
	double* marks;
	int counter;


public:
	Grades() :studentID(nullptr), marks(nullptr), counter(0){

	}

	Grades(char* fileName){
			std::ifstream file(fileName);
			if (file.is_open()==true){
				std::string temporal;
				int count = 0;

                //Count records's numbers
				while (getline(file, temporal)){
					count++;
				}
                //Reset file and goes to the beginning
				file.clear();
				file.seekg(0);
				counter = count;
				studentID = new std::string[counter];
				marks = new double[counter];

				for (int i = 0; i < counter; i++){
                file >> studentID[i];
                file >> marks[i];
				}
				file.close();
			}
			else {
				std::cerr << "File is missing!";
			}

	}

	~Grades(){
		delete[] studentID;
		delete[] marks;
	}

	template<typename Func>
	void displayGrades(std::ostream& os, Func letterMark) const{
		for (int i = 0; i < counter; i++){
			os << studentID[i] << " " << marks[i] << " " << letterMark(marks[i]) << std::endl;
		}
	}

};
