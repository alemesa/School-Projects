#ifndef CAT_H
#define CAT_H

#include "Pet.h"

class Cat : public Pet
{
public:
	Cat(void);
	~Cat(void);

	virtual void Move();
};

#endif