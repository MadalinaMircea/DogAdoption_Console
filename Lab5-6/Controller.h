#pragma once
#include "FileRepository.h"

class Controller
{
public:
	FileRepository* repo;

	/*Constructor for the Controller*/
	Controller(FileRepository* repo);
	/*Destructor for the Controller*/
	~Controller();
	/*
	Tries to add a dog to the Repository.
	input - breed, an array of chars
		  - name, an array of chars
		  - age, a positive integer
		  - photo, an array of chars
	output - if a dog with this breed and name exists, returns 0 and does not add it, otherwise adds it and
	returns 1*/
	void add(string breed, string name, int age, string photo);
	/*
	Tries to remove a dog from the Repository.
	input - breed, an array of chars
		  - name, an array of chars
	output - if a dog with this breed and name exists, returns 1 and removes it, otherwise returns 0*/
	void remove(string breed, string name);
	/*
	Tries to update a dog to the Repository.
	input - breed, an array of chars
		  - name, an array of chars
		  - age, a positive integer
		  - photo, an array of chars
		  - newBreed, an array of chars
		  - newName, an array of chars
	output - if a dog with this breed and name exists, returns 1 and updates the information, otherwise returns 0
	*/
	void update(string breed, string name, int newAge, string newPhoto, string newBreed, string newName);

private:
	/*
	Searcher for a dog with this information
	input - breed, an array of characters
		  - name, an array of characters
	output - returns the position of the dog or -1 if it does not exist
	*/
	int find(string breed, string name);
};