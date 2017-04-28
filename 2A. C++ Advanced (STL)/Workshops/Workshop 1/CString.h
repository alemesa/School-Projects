/*
OOP345
Workshop 1
Title    : From One Translation Unit to Another
Date     : 02/28/17

Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#ifndef CSTRING_
#define CSTRING_
#define MAX 3

namespace w1
{
  class CString {
  private:
    char _string[MAX+1];
  public:
    CString(const char *string);
    void display(std::ostream &ostream) const;
  };
  std::ostream &operator<<(std::ostream &ostream, const CString &cstring);
}

#endif
