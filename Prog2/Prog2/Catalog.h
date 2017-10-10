#ifndef CATALOG
#define CATALOG
#include <iostream>
#include "LList.h"
class Catalog {
public:
	Catalog();	//creates new list(on heap)
	void print();	//calls prints from linked list
	void insert();	//calls insert from linked list with make() as paramater
	void del();	//calls delete from linked list
	void close();	//deallocates list
	Fruit *make();	//makes a new fruit from input
private:
	LList *list;
};
#endif