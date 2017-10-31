#include "Fruit.h"
//#define TESTING_FRUIT
Fruit::Fruit()
{
	name;
}

bool Fruit::operator>(Fruit &a)
{
	for (int i = 0; i < a.MAX_NAME_LEN; i++)
	{
		if (name[i] > a.name[i]) {
			return true;
		}
		else if (name[i] < a.name[i]) {
			return false;
		}
	}
	return false;
}

bool Fruit::operator==(Fruit &a) const
{
	for (int i = 0; i < CODE_LEN; i++) {
		if (code[i] != a.code[i]) {
			return false;
		}
	}
	
	return true;
}

bool Fruit::operator!=(Fruit const a)
{
	if (code == a.code) {
		return false;
	}
	else if (name == a.name) {
		return false;
	}
	else {
		return true;
	}
}

void Fruit::operator=(Fruit const a)
{
	name = new char[MAX_NAME_LEN];
	for (int i = 0; i < MAX_NAME_LEN; i++) {
		name[i] = a.name[i];
	}
	for (int i = 0; i < CODE_LEN; i++) {
		code[i] = a.code[i];
	}
}

ostream & operator<<(ostream & out, const Fruit *a)
{
	bool end = false;
	for (int i = 0; i < a->MAX_NAME_LEN + 1; i++) {
		if (a->name[i] != '\0' && !end) {
			out << a->name[i];
		}
		else {
			end = true;
			out << ' ';
		}
	}
	out << a->code;
	return out;
}

istream & operator >> (istream & in, Fruit &a)
{
	char *tmpptr = new char[a.MAX_NAME_LEN + 1];
	int length = 0;
	in >> tmpptr;
	for (int i = 0; i < a.MAX_NAME_LEN + 1; i++) {
		if (tmpptr[i] != '\0') {
			length++;
		}
		else {
			length++;
			break;
		}
	}
	a.name = new char[length];
	strcpy(a.name, tmpptr);
	delete[] tmpptr;


	tmpptr = new char[a.CODE_LEN + 1];
	in >> tmpptr;
	strcpy(a.code, tmpptr);
	delete[] tmpptr;

	return in;
}
#ifdef TESTING_FRUIT

// ------------------------------
// Testbed main
// ------------------------------
void main()
{
#include <iostream>
	// .... etc, to test all the methods.
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

	Fruit *test = new Fruit();
	cin >> *test;
	cout << *test;
	cout << *test == *test;
	cout << *test != *test;

	Fruit *test2 = new Fruit();
	cin >> *test2;

	cout << test > test2;


	delete test;
	delete test2;


	_CrtDumpMemoryLeaks();
	int pause;
	cin >> pause;
}

#endif
