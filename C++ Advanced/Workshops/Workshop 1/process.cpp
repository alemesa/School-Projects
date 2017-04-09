/*
OOP345
Workshop 1
Title    : From One Translation Unit to Another
Date     : 02/28/17

Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#include <iostream>
#include "CString.h"
#include "process.h"

using namespace w1;

void process(const char *str)
{
  CString cStr(str);
  std::cout << cStr << std::endl;
}
