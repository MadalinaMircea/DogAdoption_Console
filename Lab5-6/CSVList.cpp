#include "CSVList.h"
#include <fstream>
#include "Windows.h"
using namespace std;

void CSVList::writeToFile()
{
	ofstream file(this->fileName);

	for (auto d : this->dogs.elems)
		file << d;

	file.close();
}



void CSVList::displayList()
{
	string aux = "\"" + this->fileName + "\"";
	ShellExecuteA(NULL, NULL, "c:\\Windows\\System32\\notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}