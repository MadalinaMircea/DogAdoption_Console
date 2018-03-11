#include "HTMLList.h"
#include <fstream>
#include "Windows.h"

void HTMLList::writeToFile()
{
	ofstream file(this->fileName);

	file << "<!DOCTYPE html>\n\
<html>\n\
	<head>\n\
		<title>Adoption List</title>\n\
	</head>\n\
	<body>\n\
		<table border = \"1\">\n\
			<tr>\n\
				<td>Breed</td>\n\
				<td>Name</td>\n\
				<td>Age</td>\n\
				<td>Photo link</td>\n\
			</tr>\n";

	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		file << "			<tr>\n\
				<td>" << this->dogs.elems[i].getBreed() << "</td>\n\
				<td>" << this->dogs.elems[i].getName() << "</td>\n\
				<td>" << this->dogs.elems[i].getAge() << "</td>\n\
				<td><a href=\"" << this->dogs.elems[i].getPhoto() << "\">Open</td>\n\
			</tr>\n";
	}

	file << "		</table>\n\
	</body>\n\
</html>";

	file.close();
}

void HTMLList::displayList()
{
	string aux = "\"file:///E:/Lab5-6/Lab5-6/" + this->fileName + "\"";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}