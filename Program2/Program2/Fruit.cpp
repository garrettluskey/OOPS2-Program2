#include "Fruit.h"

Fruit::Fruit(char *in, char *code)
{

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
	for (int i = 0; i < CODE_LEN; i++)
	{
		if (code[i] == a.code[i]) {
			return false;
		}
	}
	return true;
}

ostream & operator<<(ostream & out, Fruit a)
{
	char *output = new char[MAX_NAME_LEN];
	for (int i = 0; i < MAX_NAME_LEN; i++) {
		*out << *name[i];
	}
}
