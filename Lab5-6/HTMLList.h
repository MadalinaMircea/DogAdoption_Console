#pragma once
#include "FileRepository.h"

class HTMLList : public FileRepository
{
public:
	HTMLList() { this->fileName = "adoptionList.html"; };
	HTMLList(std::string name) { this->fileName = name; };
	~HTMLList() {};
	void writeToFile() override;
	void displayList() override;
};