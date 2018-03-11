#include "Validator.h"

const char* ValidatorException::what()
{
	this->printable = "";

	for (int i = 0; i < this->errors.size(); i++)
		this->printable = this->printable + '\n' + this->errors[i];

	return this->printable.c_str();
}

void Validator::validate(Dog& d)
{
	vector<string> errors;

	if (d.getBreed().length() == 0)
		errors.push_back("Breed can not be empty.");

	if (d.getName().length() == 0)
		errors.push_back("Name can not be empty.");

	if (d.getPhoto().length() == 0)
		errors.push_back("Photo can not be empty.");

	if (d.getAge() < 0)
		errors.push_back("Age can not be negative.");

	if (d.getPhoto().find("www") != 0 && d.getPhoto().find("http") != 0)
		errors.push_back("Photo link not valid.");

	if (errors.size() > 0)
		throw ValidatorException(errors);
}