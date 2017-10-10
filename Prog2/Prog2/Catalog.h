#ifndef CATALOG
#define CATALOG
#include <iostream>
#include "LList.h"
class Catalog {
public:
	Catalog();
	void print();
	void insert();
	void del();
	void close();
	Fruit *make();
private:
	LList *list;
};
#endif