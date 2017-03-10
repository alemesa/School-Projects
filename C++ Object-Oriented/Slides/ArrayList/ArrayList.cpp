#include <iostream>
#include "ArrayList.h"
using namespace std;

namespace cornel
{
	ArrayList::ArrayList(void)
	{
		cout << "ArrayList()" << endl;
		this->m_size = 0;
		this->m_pItems = nullptr;
	}

	ArrayList::ArrayList(int item)
	{
		cout << "ArrayList(int)" << endl;
		this->m_size = 0;
		this->m_pItems = nullptr;
		this->Add(item);
	}

	ArrayList::~ArrayList(void)
	{
		cout << "~ArrayList()" << endl;
		if (nullptr != this->m_pItems)
		{
			delete[] this->m_pItems;
		}
	}

	void ArrayList::Display() const
	{
		for (unsigned int i = 0; i < this->m_size; ++i)
		{
			cout << this->m_pItems[i] << "  ";
		}
	}

	void ArrayList::Add(int item)
	{
		int* temp = new int[this->m_size + 1];
		for (unsigned int i = 0; i < this->m_size; ++i)
		{
			temp[i] = this->m_pItems[i];
		}
		temp[this->m_size] = item;
		delete[] this->m_pItems;
		this->m_pItems = temp;
		++this->m_size;
	}

	unsigned int ArrayList::GetSize() const
	{
		return this->m_size;
	}

	void ArrayList::operator+=(const ArrayList& other)
	{
		for (unsigned int i = 0; i < other.m_size; ++i)
		{
			this->Add(other.m_pItems[i]);
		}
	}

	void ArrayList::operator+=(int item)
	{
		this->Add(item);
	}

	int ArrayList::operator[] (const unsigned int& idx) const
	{
		return this->m_pItems[idx];
	}

	ArrayList::operator bool() const
	{
		cout << "operator bool" << endl;
		return this->m_size > 0;
	}
}