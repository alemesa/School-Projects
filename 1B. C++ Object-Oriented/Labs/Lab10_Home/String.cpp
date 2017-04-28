////////////////////////////////////////////////////////////////
// OOP244       Workshop 10
// File	        String.cpp
// Author		Alejandro Mesa Suarez
// Number ID    0385151
// Email        amesasuarez@myseneca.ca
////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace ict
{
   // write your implementations here
   // private functions
	void String::deallocate() {
		delete[] m_data;
		m_data = nullptr;
		m_memSize = 0;
	}
	void String::allocate(int memsize) {
		delete[] m_data;
		m_data = new char[memsize];
		m_memSize = memsize;
		//initialize first element
		m_data[0] = '\0';

	}
	void String::init(const char* str, int memSize) {
		m_data = nullptr;
		m_len = strlen(str);
		if (memSize < m_len) {
			memSize = m_len + 1;
		}
		allocate(memSize);
		strcpy(m_data, str);
		m_data[m_len + 1] = '\0';
	}
	// public functions
	void String::resize(int newsize) {
		int i;
		char* temp = new char[newsize];
		temp[0] = '\0';    
		if (m_data) {
			for (i = 0; (i < newsize - 1 && m_data[i] != '\0'); i++) {
				temp[i] = m_data[i];
			}
			temp[i] = '\0';

		}
		allocate(newsize);
		if (temp[0] != '\0') {     
			strcpy(m_data, temp);
		}
		m_len = strlen(m_data);
	}

	// special member functions
	// constructors and destructors
	String::String() {
		m_data = nullptr;
		m_memSize = 0;
		m_len = 0;
	}
	String::String(const char* str, int memsize) {
		init(str, memsize);
	}
	    // copy and assignment
	String::String(const String& str) {
		init(str.m_data, str.m_memSize);
	}
	String& String::operator=(const String& str) {
		if (this != &str) {
			delete[] m_data;
			init(str.m_data, str.m_memSize);
		}
		return *this;
	}
		//destructor
	String::~String() {
		delete[] m_data;
	}

	//copy and assignment operators
	

	// accessors
	int String::getLength()const {
		return m_len;
	}
	int String::getMemSize()const {
		return m_memSize;
	}

	// cast operators
	String::operator const char *()const {
		return m_data;
	}
	String::operator int()const {
		return strlen(m_data);
	}

	// operators
	String& String::operator++() {     
		char temp[ExpansionSize];
		strcpy(temp, " ");
		strcat(temp, m_data);
		strcpy(m_data, temp);
		m_len = strlen(m_data);
		return *this;
	}
	String String::operator++(int) {   
		String copy = *this;
		copy += " ";
		return *this;
	}
	String& String::operator+=(const char* str) {
		int strLength = strlen(str);
		if (m_len + strLength + 1 > m_memSize) {
			resize(m_len + strLength + 1);
		}
		strcat(m_data, str);
		m_len = strlen(m_data);
		return *this;
	}
	String& String::operator+=(String& str){
		*this += str.m_data;
		return *this;
	}
	String String::operator+(const String& str)const {
		String temp;
		temp.allocate(ExpansionSize);
		temp += this->m_data;
		temp += " ";
		temp += str.m_data;
		temp.m_len = strlen(temp.m_data + 1);
		return temp;
	}
	char& String::operator[](int index) {
		if (index > m_memSize - 1) {
			resize(index + ExpansionSize);
		}
		return m_data[index];
	}

	// IO 
	ostream& String::display(ostream& ostr) const {
		if (m_data != nullptr) {
			ostr << m_data;
		}
		return ostr;
	}
	istream& String::read(istream& istr) {
		char c;
		int i = 0;
		while ((c = istr.get() != '\n')) {
			if (i > m_memSize) {
				resize(m_memSize + ExpansionSize);
			}
			m_data[i] = c;
			i++;
		}
		m_data = NULL;
		return istr;
	}

	//IO Non-member opertors
	ostream& operator<<(ostream& ostr, const String &s) {
		s.display(ostr);
		return ostr;
	}
	
	istream& operator >> (istream& istr, String &s) {
		s.read(istr);
		return istr;
	}
}
