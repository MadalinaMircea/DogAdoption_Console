#pragma once
#include<iostream>
#include<string>
using namespace std;

class Dog
{
private:
	string breed, name, photo;
	int age;

public:
	static int currentInstances;
	static int allInstances;

	static int getCurrentInstances();
	static int getAllInstances();

	Dog()
	{
		this->breed = "";
		this->name = "";
		this->age = 0;
		this->photo = "";

		currentInstances++;
		allInstances++;
	}

	Dog(const Dog& dog)
	{
		this->breed = dog.breed;
		this->name = dog.name;
		this->photo = dog.photo;
		this->age = dog.age;

		currentInstances++;
		allInstances++;
	}
	~Dog()
	{
		currentInstances--;
	}

	string getBreed() { return this->breed; }
	string getName() { return this->name; }
	string getPhoto() { return this->photo; }
	int getAge() { return this->age; }

	/*Constructor for the Dog*/
	Dog(string &dogBreed, string &dogName, int dogAge, string &dogPhoto);
	/*
	Modifies the age of a dog
	input - newAge, a positive integer
	output - the age of the dog is updated
	*/
	void setAge(int newAge);

	bool operator==(const Dog& dog) const;
	/*
	Modifies the photo of a dog
	input - newPhoto, an array of characters
	output - the photo of the dog is updated
	*/
	void setPhoto(string newPhoto);
	/*
	Modifies the breed of a dog
	input - newBreed, an array of characters
	output - the breed of the dog is updated
	*/
	void setBreed(string newBreed);
	/*
	Modifies the name of a dog
	input - newName, an array of characters
	output - the name of the dog is updated
	*/
	void setName(string newName);

	void showPicture();

	friend istream& operator>>(istream& is, Dog& d);
	friend ostream& operator<<(ostream& os, const Dog& d);
};