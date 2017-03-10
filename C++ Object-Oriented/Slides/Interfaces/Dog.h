#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet
{
public:
	Dog(void);
	Dog(const Dog&);
	~Dog(void);

	// from Pet
	virtual void Move();

	// from Serialization
	virtual void Serialize(std::ostream&);
	// restores the state
	virtual void Deserialize(std::istream&);
};

#endif