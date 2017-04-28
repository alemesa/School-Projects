#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String::String(void)
{
	cout << "String():     " << this << endl;
	this->m_pString = nullptr;
	this->m_size = 0;
}

String::~String(void)
{
	cout << "~String():    " << this << endl;
	if (nullptr != this->m_pString)
	{
		delete[] this->m_pString;
	}
}

void String::Set(const char* pString)
{
	if (nullptr != this->m_pString)
	{
		delete[] this->m_pString;
		this->m_size = 0;
		this->m_pString = nullptr;
	}

	if (nullptr != pString)
	{
		this->m_size = strlen(pString);
		this->m_pString = new char[this->m_size + 1];
		this->m_pString[this->m_size] = '\0';
		strncpy(this->m_pString, pString, this->m_size);
	}
}

void String::Display() const
{
	cout << "  this: " << this << "  &m_size: " << &this->m_size << "  m_size: " << this->m_size;
	cout << "  &m_pString: " << (void*)&this->m_pString << "  m_pString: " << (void*)this->m_pString;
	if (nullptr != this->m_pString)
	{
		cout << "  *m_pString: " << this->m_pString;
	}
	cout << endl;
}
