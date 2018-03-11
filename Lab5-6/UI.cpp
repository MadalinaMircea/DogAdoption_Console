#include "UI.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include"Others.h"
#include "Exceptions.h"
#include "Validator.h"
#include "HTMLList.h"
using namespace std;

UI::UI(Controller* ctrl)
{
	this->ctrl = ctrl;
}

UI::~UI()
{
	delete ctrl;
}
void UI::printCommandsAdmin()
{
	cout << "\nType:\n\
	'1' - add a dog\n\
	'2' - remove a dog\n\
	'3' - update a dog\n\
	'4' - list all dogs\n\
	'5' - show number of instances\n\
	'0' - exit\n\n";
}

void UI::printCommandsUser()
{
	cout << "\nType:\n\
	'1' - see all the dogs\n\
	'2' - see filtred dogs\n\
	'3' - see adoption list\n\
	'0' - adopt and exit\n\n";
}

void UI::add()
{
	string breed, name, photo, agec;
	int age;

	cout << "Give the breed: ";
	getline(cin, breed);

	cout << "Give the name: ";
	getline(cin, name);

	cout << "Give the age: ";
	getline(cin, agec);

	cout << "Give the photograph link: ";
	getline(cin, photo);

	age = stringToInt(agec);

	try
	{
		this->ctrl->add(breed, name, age, photo);
		cout << "The dog has been added.\n";
	}
	catch (DuplicateDogException& e)
	{
		cout << e.what() << '\n';
	}
	catch (ValidatorException& v)
	{
		cout << v.what() << '\n';
	}
	catch (...)
	{
		cout << "Controller Add Exception.\n";
	}
}

void UI::remove()
{

	string breed, name;

	cout << "Give the breed: ";
	getline(cin, breed);

	cout << "Give the name: ";
	getline(cin, name);

	try
	{
		this->ctrl->remove(breed, name);
		cout << "The dog has been removed.\n";
	}
	catch (DogNotFoundException& e)
	{
		cout << e.what();
	}
	catch (ValidatorException& e)
	{
		cout << e.what();
	}
	catch (...)
	{
		cout << "Controller Remove Exception\n";
	}
}

void UI::update()
{
	string breed, name, photo, agec, newBreed, newName;
	int age;

	cout << "Give the breed: ";
	getline(cin, breed);

	cout << "Give the name: ";
	getline(cin, name);

	cout << "Give the new breed (ENTER for unchanged): ";
	getline(cin, newBreed);

	cout << "Give the new name (ENTER for unchanged): ";
	getline(cin, newName);

	cout << "Give the new age (ENTER for unchanged): ";
	getline(cin, agec);

	cout << "Give the new photo link (ENTER for unchanged): ";
	getline(cin, photo);

	age = stringToInt(agec);

	try
	{
		this->ctrl->update(breed, name, age, photo, newBreed, newName);
		cout << "The information had been updated.\n";
	}
	catch (DogNotFoundException& e)
	{
		cout << e.what();
	}
	catch (ValidatorException& e)
	{
		cout << e.what();
	}
	catch (...)
	{
		cout << "Controller Update Exception\n";
	}
}

void printDog(Dog dog)
{
	cout << left << setw(20) << dog.getBreed() << setw(20) << dog.getName() << setw(6) << dog.getAge() << dog.getPhoto() << '\n';
}

void UI::listAll(Repository* repo)
{
	if (repo->dogs.getSize() == 0)
		cout << "The list is empty.\n";
	else
	{
		cout << left << setw(20) << "Breed" << setw(20) << "Name" << setw(6) << "Age" << "Photo\n";
		cout << "_______________________________________________________________________________________\n";
		for (auto d : repo->dogs.elems)
			printDog(d);
	}
}

void listInstances()
{
	cout << "Current instances: " << Dog::getCurrentInstances() << '\n';
	cout << "All instances: " << Dog::getAllInstances() << '\n';
}

void UI::startAdmin()
{
	int keepAlive = 1;
	char cmd;

	while (keepAlive)
	{
		this->printCommandsAdmin();

		cout << "Give command: ";
		cin >> cmd; cin.get();

		if (cmd == '1')
			this->add();
		else if (cmd == '2')
			this->remove();
		else if (cmd == '3')
			this->update();
		else if (cmd == '4')
			this->listAll(this->ctrl->repo);
		else if (cmd == '5')
			listInstances();
		else if (cmd == '0')
			keepAlive = 0;
		else
			cout << "Invalid input.";
	}
}

void printOptions()
{
	cout << "\nType:\n\
	'1' - show picture\n\
	'2' - adopt\n\
	'3' - next\n\
	'0' - exit\n\
Give command: ";
}

void UI::showAll(Repository* repo, FileRepository* adoptionList)
{
	int alive = 1, i = 0, length = repo->dogs.getSize();
	char mode;
	
	while (alive && length > 0)
	{
		if (i == length)
			i = 0;

		printDog(repo->dogs.elems[i]);
		printOptions();
		cin >> mode;

		if (mode == '1')
			repo->dogs.elems[i].showPicture();
		else if (mode == '2')
		{
			adoptionList->add(repo->dogs.elems[i]);
			adoptionList->writeToFile();
			cout << '\n' << repo->dogs.elems[i].getName() << " has been added to your adoption list!\n\n";
			this->ctrl->remove(repo->dogs.elems[i].getBreed(), repo->dogs.elems[i].getName());
			if(repo != this->ctrl->repo)
				repo->remove(i);
			length--;
		}
		else if (mode == '3')
			i++;
		else if (mode == '0')
			alive = 0;
		else
			cout << "Invalid input.\n";
	}

	if (length == 0)
		cout << "There are no dogs available.";
}

void UI::showFiltered(FileRepository* adoptionList)
{
	Repository* filtered = new Repository;

	string breed, agec;
	int age;

	cout << "Give the breed: ";
	getline(cin, breed);

	cout << "Give age: ";
	getline(cin, agec);

	age = stringToInt(agec);

	if (age == 0)
		cout << "Invalid input.\n";
	else
	{
		if (breed.size() == 0)
		{
			for (auto d : this->ctrl->repo->dogs.elems)
				if (d.getAge() < age)
					filtered->add(d);
		}
		else
		{
			for (auto d : this->ctrl->repo->dogs.elems)
				if (d.getBreed() == breed && d.getAge() < age)
					filtered->add(d);
		}

		showAll(filtered, adoptionList);
	}

	delete filtered;
}

void UI::adopt(FileRepository adoptionList)
{
	if (adoptionList.dogs.getSize() == 1)
		cout << "Thank you for adopting one dog!\n";
	else if(adoptionList.dogs.getSize() != 0)
		cout << "Thank you for adopting " << adoptionList.dogs.getSize() << " dogs!\n";
}


void UI::startUser()
{
	int keepAlive = 1;
	char cmd;
	char type;

	cout << "Type:\n\
	'1' - save in a CSV file\n\
	'2' - save in a HTML file\n\
Give command: ";

	cin >> type;

	FileRepository* adoptionList;

	if (type == '1')
	{
		adoptionList = new CSVList;
	}
	else
	{
		adoptionList = new HTMLList;
	}

	adoptionList->writeToFile();

	while (keepAlive)
	{
		this->printCommandsUser();

		cout << "Give command: ";
		cin >> cmd; cin.get();

		if (cmd == '1')
			this->showAll(this->ctrl->repo, adoptionList);
		else if (cmd == '2')
			this->showFiltered(adoptionList);
		else if (cmd == '3')
			adoptionList->displayList();
		else if (cmd == '0')
		{
			adopt(*adoptionList);
			keepAlive = 0;
		}
		else
			cout << "Invalid input.";
	}

	delete adoptionList;
}

void UI::start()
{
	cout << "Welcome!\n";

	char mode;
	int still = 1;

	while (still)
	{
		cout << "Open in:\n\
	'1' - Administrator mode\n\
	'2' - User mode\n\
	'0' - exit\n\
Give mode: ";
		cin >> mode; cin.get();

		if (mode == '1')
			this->startAdmin();
		else if (mode == '2')
			this->startUser();
		else if (mode == '0')
			still = 0;
		else
			cout << "Invalid input.";
	}

	cout << "Goodbye!\n";
}
