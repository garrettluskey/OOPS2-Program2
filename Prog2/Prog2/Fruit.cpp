#include "Fruit.h"

Fruit::Fruit()
{
	name = NULL;
	code[CODE_LEN];
}

Fruit::~Fruit()
{
	if (name != NULL) {
		delete[] name;
		name = NULL;
	}
	
}

bool Fruit::operator>(Fruit a)
{
	for (int i = 0; i < CODE_LEN; i++)
	{
		if (code[i] > a.code[i]) {
			return true;
		}
		else if (code[i] < a.code[i]) {
			return false;
		}
	}
	return false;
}

bool Fruit::operator==(Fruit *a) const
{
	for (int i = 0; i < CODE_LEN; i++) {
		if (code[i] != a->code[i]) {
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
	for (int i = 0; i < a->MAX_NAME_LEN; i++) {
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
	for (int i = 0; i < length; i++) {
		if (tmpptr[i] != '\0') {
			a.name[i] = tmpptr[i];
		}
		else {
			a.name[i] = '\0';
			break;
		}
	}
	delete tmpptr;
	in >> a.code;
	return in;
}
