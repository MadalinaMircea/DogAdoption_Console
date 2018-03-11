#pragma once
#include "FileRepository.h"

class CSVList : public FileRepository
{
public:
	CSVList() { this->fileName = "adoptionList.txt"; }
	CSVList(std::string name) { this->fileName = name; }
	~CSVList() {};
	void writeToFile() override;
	void displayList() override;
};