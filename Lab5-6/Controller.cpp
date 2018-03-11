#include "Controller.h"
#include "Exceptions.h"
#include "Validator.h"

Controller::Controller(FileRepository* repo)
{
	this->repo = repo;
}

Controller::~Controller()
{
	delete repo;
}

void Controller::add(string breed, string name, int age, string photo)
{
	int index = this->find(breed, name);

	if (index != -1)
		throw DuplicateDogException("A dog with this information already exists!\n");
	
	Dog dog = Dog(breed, name, age, photo);

	Validator::validate(dog);

	this->repo->add(dog);
	this->repo->writeToFile();
}

void Controller::remove(string breed, string name)
{
	int index = this->find(breed, name);

	if (index == -1)
		throw DogNotFoundException("A dog with this information does not exist!\n");

	string photo = "www";

	Dog d = Dog(breed, name, 0, photo);

	Validator::validate(d);
	
	this->repo->remove(index);
	this->repo->writeToFile();
}

void Controller::update(string breed, string name, int newAge, string newPhoto, string newBreed, string newName)
{
	int index = this->find(breed, name);

	if (index == -1)
		throw DogNotFoundException("A dog with this information does not exist!\n");
	
	if (newBreed.length() == 0)
		newBreed = breed;
	if (newName.length() == 0)
		newName = name;
	if (newPhoto.length() == 0)
		newPhoto = this->repo->dogs.elems[index].getPhoto();
	if (newAge == 0)
		newAge = this->repo->dogs.elems[index].getAge();

	Dog d = Dog(newBreed, newName, newAge, newPhoto);

	Validator::validate(d);

	this->repo->update(index, d);
	this->repo->writeToFile();
}

int Controller::find(string breed, string name)
{
	Dog d = Dog(breed, name, 0, breed);

	vector<Dog>::iterator it = std::find(this->repo->dogs.elems.begin(), this->repo->dogs.elems.end(), d);

	if (it == this->repo->dogs.elems.end())
		return -1;

	return it - this->repo->dogs.elems.begin();
}
