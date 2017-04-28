#ifndef FOO_H
#define FOO_H
#include <ostream>

class Foo
{
  private:
    char m_msg[4];
    int m_size;
    char* m_pName;
  public:
    Foo();
    void SetMsg(const char* msg);
	friend std::ostream& operator<<(std::ostream&, const Foo&);
};

#endif