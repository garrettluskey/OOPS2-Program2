#ifndef CATALOG
#define CATALOG
#include <iostream>
#include "LList.h"
class Catalog {
public:
	void print();
	void insert();
	void del();
	Fruit *make();
private:
	LList list;
};
#endif