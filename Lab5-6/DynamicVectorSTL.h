#pragma once
#include "Dog.h"
#include <iostream>
#include<vector>
using namespace std;

template<typename TElem>
class DynamicVectorSTL
{
public:
	vector<TElem> elems;

	/*Constructor for the DynamicVectorSTL*/
	DynamicVectorSTL() {}
	~DynamicVectorSTL() {}
	/*Copy constructor*/
	DynamicVectorSTL(DynamicVectorSTL<TElem>& v);
	DynamicVectorSTL operator+(TElem& e)
	{
		this->elems.push_back(e);

		return *this;
	}
	DynamicVectorSTL<TElem> operator=(DynamicVectorSTL& v);
	TElem& operator[](int i);
	/*
	Removes a dog from the DynamicVectorSTL.
	input - index, an integer representing the position of the object to be deleted
	output - the pointer is removed from the dogList and destroyed
	*/
	void remove(int index);
	/*
	Updates the information of a dog from the DynamicVectorSTL
	input - index, an integer representing the position of the object to be updated
	- newAge, an integer representing the new age of the dog
	- newPhoto, an array of characters representing the new link
	- newBreed, an array of characters representing the new breed
	- newName, an array of characters representing the new breed
	output - the information of the dog located on position index is updated
	*/
	void update(int index, TElem& e);
	int getSize() { return elems.size(); };
};

template<class TElem>
DynamicVectorSTL<TElem> operator+(TElem& e, DynamicVectorSTL<TElem>& v)
{
	v.elems.push_back(e);

	return v;
}

template<class TElem>
DynamicVectorSTL<TElem>::DynamicVectorSTL(DynamicVectorSTL<TElem>& v)
{
	for (auto d : v.elems)
		this->elems.push_back(d);
}

template<class TElem>
DynamicVectorSTL<TElem> DynamicVectorSTL<TElem>::operator=(DynamicVectorSTL& v)
{
	while (this->getSize() != 0)
		this->remove(0);

	for (auto d : v.elems)
	{
		this->elems.push_back(d);
	}

	return *this;
}

template<class TElem>
TElem& DynamicVectorSTL<TElem>::operator[](int i)
{
	return this->elems[i];
}

template<class TElem>
void DynamicVectorSTL<TElem>::remove(int index)
{
	vector<TElem>::iterator it = this->elems.begin();
	advance(it, index);
	this->elems.erase(it);
}

template<class TElem>
void DynamicVectorSTL<TElem>::update(int index, TElem& e)
{
	this->elems[index] = e;
}
