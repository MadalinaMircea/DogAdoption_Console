#pragma once
#include "Controller.h"
#include<iostream>
#include "CSVList.h"

class UI
{
public:
	Controller* ctrl;

	UI(Controller* ctrl);
	~UI();
	void start();

private:
	void printCommandsAdmin();
	void printCommandsUser();
	void add();
	void remove();
	void update();
	void listAll(Repository* repo);
	void startUser();
	void startAdmin();
	void showAll(Repository* repo, FileRepository* adoptionList);
	void showFiltered(FileRepository* adoptionList);
	void adopt(FileRepository adoptionList);
};