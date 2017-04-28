#ifndef STRING_H
#define STRING_H

class String
{
	unsigned int m_size;
	char* m_pString;
public:
	String(void);
	~String(void);

	void Set(const char* pString);
	void Display() const;
};

#endif