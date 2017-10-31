#ifndef LLIST
#define LLIST

#include "Fruit.h"
typedef Fruit InfoType;
#include <iostream>
using namespace std;
class LList
{
public:
	LList() { list = NULL; }
	~LList();    // delete all the nodes
	bool IsEmpty() const; //is list empty?
	bool Insert(InfoType * x_ptr); //inserts into list where name is alphabetically ordered
	bool Delete(InfoType *x); // deletes node from list
	void Display(ostream & out_stream) const; //prints list

private:
	struct Node;
	Node *list;
	LList(const LList & copyFrom);                 // Don't allow!
	LList & operator= (const LList & assignFrom);   // Don't allow!
};
#endif // !LLIST