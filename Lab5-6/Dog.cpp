#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include <sstream>
#include "Others.h"

int Dog::currentInstances = 0;
int Dog::allInstances = 0;
int Dog::getCurrentInstances()
{
	return currentInstances;
}
int Dog::getAllInstances()
{
	return allInstances;
}
Dog::Dog(string &dogBreed, string &dogName, int dogAge, string &dogPhoto)
{
	this->breed = dogBreed;

	this->name = dogName;

	this->age = dogAge;

	this->photo = dogPhoto;

	currentInstances++;
	allInstances++;
}
void Dog::showPicture()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->photo.c_str(), NULL, SW_SHOWMAXIMIZED);
}
void Dog::setAge(int newAge)
{
	this->age = newAge;
}
void Dog::setPhoto(string newPhoto)
{
	this->photo = newPhoto;
}
void Dog::setBreed(string newBreed)
{
	this->breed = newBreed;
}
void Dog::setName(string newName)
{
	this->name = newName;
}

bool Dog::operator==(const Dog& dog) const
{
	if (this->name == dog.name && this->breed == dog.breed)
		return true;

	return false;
}

istream& operator>>(istream& is, Dog& d)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;

	d.breed = tokens[0];
	d.name = tokens[1];
	d.age = stringToInt(tokens[2]);
	d.photo = tokens[3];

	return is;

}

ostream& operator<<(ostream& os, const Dog& d)
{
	os << d.breed << "," << d.name << "," << d.age << "," << d.photo << '\n';
	return os;
}