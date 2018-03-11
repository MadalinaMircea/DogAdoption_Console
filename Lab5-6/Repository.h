#pragma once
#include "Dog.h"
#include "DynamicVectorSTL.h"

class Repository
{
public:
	DynamicVectorSTL<Dog> dogs;
	Repository() {}
	virtual ~Repository() {}
	void init();
	/*
	Adds a dog to the Repository.
	input - dog, a pointer to a Dog type object
	output - the pointer is added to the dogList
	*/
	virtual void add(Dog& dog);
	/*
	Removes a dog from the Repository.
	input - index, an integer representing the position of the object to be deleted
	output - the pointer is removed from the dogList and destroyed
	*/
	virtual void remove(int index);
	/*
	Updates the information of a dog from the Repository
	input - index, an integer representing the position of the object to be updated
		  - newAge, an integer representing the new age of the dog
		  - newPhoto, an array of characters representing the new link
		  - newBreed, an array of characters representing the new breed
		  - newName, an array of characters representing the new breed
	output - the information of the dog located on position index is updated
	*/
	virtual void update(int index, Dog& d);
};