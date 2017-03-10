#pragma once
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

namespace cornel
{
	class ArrayList
	{
		int* m_pItems;
		unsigned int m_size;
	public:
		ArrayList(void);
		ArrayList(int);
		~ArrayList(void);

		void Add(int item);
		void Display() const;
		unsigned int GetSize() const;

		void operator+= (const ArrayList& other);
		void operator+= (int item);
		int operator[] (const unsigned int& idx) const;
		operator bool() const;
	};
}

#endif