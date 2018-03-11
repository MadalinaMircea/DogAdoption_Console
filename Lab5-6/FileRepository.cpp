#include "FileRepository.h"
#include <fstream>
#include "Exceptions.h"
using namespace std;

void FileRepository::loadFromFile()
{
	ifstream file(this->fileName);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Dog d;
	while (file >> d)
		this->add(d);

	file.close();
}


void FileRepository::displayList() {}

void FileRepository::writeToFile() {}
