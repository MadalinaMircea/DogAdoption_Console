#include "Exceptions.h"

const char* FileException::what()
{
	return this->msg.c_str();
}

const char* DuplicateDogException::what()
{
	return this->msg.c_str();
}

const char* DogNotFoundException::what()
{
	return this->msg.c_str();
}