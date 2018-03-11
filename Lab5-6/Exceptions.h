#pragma once
#include <exception>
#include <string>
using namespace std;

class FileException : public exception
{
protected:
	string msg;
public:
	FileException(const string msg) { this->msg = msg; }
	virtual const char* what();
};


class DuplicateDogException : public exception
{
protected:
	string msg;
public:
	DuplicateDogException(const string msg) { this->msg = msg; }
	virtual const char* what();
};

class DogNotFoundException : public exception
{
protected:
	string msg;
public:
	DogNotFoundException(const string msg) { this->msg = msg; }
	virtual const char* what();
};