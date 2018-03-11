#include<iostream>
#include "Windows.h"
#include "UI.h"
#include "crtdbg.h"
#include "tests.h"
#include "FileRepository.h"
#include "Exceptions.h"
using namespace std;

void secondMain()
{	

	try
	{
		FileRepository* repo = new CSVList("dogs.txt");
		repo->loadFromFile();

		Controller* ctrl = new Controller{ repo };
		UI* ui = new UI{ ctrl };

		ui->start();

		delete ui;
	}
	catch (FileException& e)
	{
		cout << e.what() << '\n';
	}
	
}

int main()
{
	//runAllTests();

	secondMain();
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	
	system("pause");
	
	return 0;
}