#pragma once
#include "Dog.h"
#include <vector>
#include<string>
#include <exception>
using namespace std;

class ValidatorException : public exception
{
public:
	vector<string> errors;
	string printable;
	ValidatorException(vector<string> errors) { this->errors = errors; }
	const char* what();
};

class Validator
{
public:
	Validator() {}
	static void validate(Dog& s);
};