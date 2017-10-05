#ifndef FRUIT
#define FRUIT

#include <iostream>
using namespace std;
class LList
{
public:
	LList();
	~LList();    // delete all the nodes
	bool IsEmpty() const;
	bool Insert(InfoType * x_ptr);
	bool Delete(const InfoType & x);
	void Display(ostream & out_stream) const;

private:
	struct Node;
	Node * list;
	LList(const LList & copyFrom);                 // Don't allow!
	LList & operator= (const LList & assignFrom);   // Don't allow!
};

#endif