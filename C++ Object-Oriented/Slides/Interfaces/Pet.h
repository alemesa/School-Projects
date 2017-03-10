#ifndef PET_H
#define PET_H
#include <string>
#include "Serializable.h"

class Pet : public Serializable
{
protected:
	std::string m_name;
public:
	Pet(void);
	Pet(const Pet&);
	virtual ~Pet(void);

	void SetName(std::string name);

	virtual void Move() = 0;
};

#endif