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
	bool IsEmpty() const;
	bool Insert(InfoType * x_ptr);
	bool Delete(InfoType *x);
	void Display(ostream & out_stream) const;

private:
	struct Node;
	Node *list;
	LList(const LList & copyFrom);                 // Don't allow!
	LList & operator= (const LList & assignFrom);   // Don't allow!
};
#endif // !LLIST