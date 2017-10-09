#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;
#include "LeakWatcher.h"
#include "LList.h"
#include "Catalog.h"
#include <string>

int main()
{
	const int MAX_INPUT_LEN = 34;
	//-------------------------------------------------------
	// Don't touch any of this!
	//-------------------------------------------------------

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	char *input = new char[MAX_INPUT_LEN];
	Catalog fruits;
	while (input[0] != 'S') {
		
		cin >> input;
		if (input[0] == 'I') {
			fruits.insert();
		}
		else if (input[0] == 'D') {
			fruits.del();
		}
		else if (input[0] == 'P') {
			fruits.print();
		}
		
		else if(isdigit(input[0])){
			cout << "There are " << input << " types of fruits initially in the list.\n";
			cout << "They will be read in and inserted in the list in order.\n";
			for (int i = 0; i < stoi(input); i++) {
				fruits.insert();
			}
		}
		else {
			cout << "Invalid command!\n";
		}
	}
	delete input;
	_CrtDumpMemoryLeaks();

	return 0;
}