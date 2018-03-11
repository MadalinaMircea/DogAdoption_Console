#pragma once
#include "Repository.h"
#include <string.h>

class FileRepository : public Repository
{
protected:
	string fileName;

public:
	FileRepository() {}

	virtual ~FileRepository() {}
	virtual void displayList();
	virtual void writeToFile();
	void loadFromFile();
};