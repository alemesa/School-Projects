#include <cstring>
#include "Foo.h"

using namespace std;

Foo::Foo(void)
{
	this->m_pName = new char[9];
	strcpy(m_pName, "John Doe");
	m_size = 9;
	strcpy(m_msg, "Hi!");
}

void Foo::SetMsg(const char* pMsg)
{
	strcpy(m_msg, pMsg);
}

ostream& operator<<(ostream& out, const Foo& theFoo)
{
	out << "Size: " << theFoo.m_size << endl;
	out << "Name: " << theFoo.m_pName << endl;
	out << "Message: " << theFoo.m_msg << endl;
	return out;
}