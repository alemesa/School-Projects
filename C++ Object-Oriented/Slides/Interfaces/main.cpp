#include <iostream>
#include <fstream>
#include <string>
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
// TODO: why there is no #include "Serializable.h" here?

using namespace std;

void Moveit(Pet* somePet)
{
	if (somePet != nullptr)
		somePet->Move();
}

void Save(Serializable* obj, string filename)
{
	// create the stream object
	ofstream out;
	// open the file
	out.open(filename);
	obj->Serialize(out);
	out.close();
}

void Load(Serializable* obj, string filename)
{
	// create the stream object and open the file
	ifstream in(filename);
	obj->Deserialize(in);
	in.close();
}

int main (void)
{
	Pet* somePet = new Dog();
	somePet->SetName("Diesel");
	Save(somePet, "output.txt");
	delete somePet;

	// loading the object from a file
	Dog* aDog = new Dog();
	Load(aDog, "output.txt");
	aDog->Move();
	delete aDog;

	// TODO: Fix the Cat class so the following code compiles.
//	Pet* anotherPet = new Cat();
//	Moveit(anotherPet);
//	delete anotherPet;

	return 0;
}
