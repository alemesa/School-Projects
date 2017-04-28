#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

class Serializable
{
public:
	Serializable()
	{
		std::clog << "[INFO] Serializable::Serializable()" << std::endl;
	}
	virtual ~Serializable()
	{
		std::clog << "[INFO] Serializable::~Serializable()" << std::endl;
	}
	// saves the state of the object
	virtual void Serialize(std::ostream&) = 0;
	// restores the state
	virtual void Deserialize(std::istream&) = 0;
};

#endif