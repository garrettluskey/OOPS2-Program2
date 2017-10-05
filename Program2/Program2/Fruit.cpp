#include "Fruit.h"
typedef Fruit InfoType;

class LList
{
public:
	LList() { list = NULL; }
	~LList();    // delete all the nodes
	bool IsEmpty() const;
	bool Insert(InfoType * x_ptr);
	bool Delete(const InfoType & x);
	void Display(ostream & out_stream) const;

private:
	struct Node
	{
		Node(InfoType * x, Node * p = NULL) { infoPtr = x;  next = p; }
		~Node() { delete infoPtr; }
		InfoType * infoPtr;
		Node * next;
	};

	Node * list;
	LList(const LList & copyFrom);                 // Don't allow!
	LList & operator= (const LList & assignFrom);   // Don't allow!
};