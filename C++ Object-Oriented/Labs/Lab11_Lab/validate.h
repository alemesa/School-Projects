//Alejandro Mesa Suarez
//083515151
//amesasuarez@myseneca.ca
//In-Lab

#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include <cstring>

namespace sict {
	template <class T>
	bool validate(const T& minimum, const T& maximum, const T* testValues, int numElements, bool* result) {
		int i = 0;
		int y = 0;
		while (i < numElements) {
			result[i] = (minimum <= testValues[i] && maximum >= testValues[i]);
			if (result[i]) {
				y++;
			}
			i++;
		}
		return y == numElements;
	}
}
#endif