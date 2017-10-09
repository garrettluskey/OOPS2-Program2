#include "Fruit.h"

Fruit::Fruit()
{
	name = new char[MAX_NAME_LEN];
	code = new char[CODE_LEN];
}

Fruit::~Fruit()
{
	delete name;
	delete code;
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
}

bool Fruit::operator==(Fruit a)
{
	for (int i = 0; i < CODE_LEN; i++)
	{
		if (code[i] != a.code[i]) {
			return false;
		}
	}
	return true;
}

bool Fruit::operator!=(Fruit a)
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

void Fruit::operator=(Fruit a)
{
	name = new char[MAX_NAME_LEN];
	code = new char[CODE_LEN];
	for (int i = 0; i < MAX_NAME_LEN; i++) {
		name[i] = a.name[i];
	}
	for (int i = 0; i < CODE_LEN; i++) {
		code[i] = a.code[i];
	}
}

ostream & operator<<(ostream & out, const Fruit a)
{
	for (int i = 0; i < a.MAX_NAME_LEN; i++) {
		if (a.name[i] != -51) {
			out << a.name[i];
		}
		else {
			out << " ";
		}
	}
	for (int i = 0; i < a.CODE_LEN; i++) {
		out << a.code[i];
	}
	return out;
}

istream & operator >> (istream & in, Fruit &a)
{
	in >> a.name;
	in >> a.code;
	return in;
}
