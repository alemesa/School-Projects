////////////////////////////////////////////////////////////////
// OOP244       Workshop 4: Constructors
// File	        w4_in_lab.cpp
// Version      1.0
// Date	        2016/10/14
// Author	    Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
// 
////////////////////////////////////////////////////////////////


#ifndef ICT_ENROLLMENT_h__
#define ICT_ENROLLMENT_h__

namespace ict {
	class Enrollment {
	
				char _name[31];
				char _code[11];
				int _year;
				int _semester;
				int _slot;
				bool _enrolled;


	public:
				bool isValid() const;
				void setEmpty();

				void display(bool nameOnly = false) const;
				bool hasConflict(const Enrollment &other) const;
				bool isEnrolled() const;
			
			
				void set(const char* nameNew, const char* codeNew, int year, int semester, int time, bool enrolled = false);
			
				Enrollment();
				Enrollment(const char* name, const char* code, int _year, int _semester, int _slot);

	};
}

#endif
