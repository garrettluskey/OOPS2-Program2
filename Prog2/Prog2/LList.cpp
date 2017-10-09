#include "LList.h"
#include "Fruit.h"
typedef Fruit InfoType;

struct LList::Node
{
	Node(InfoType * x, Node * p = NULL) { infoPtr = x;  next = p; }
	~Node() { delete infoPtr; }
	InfoType * infoPtr;
	Node * next;
};

LList::~LList()
{
	Node *P = list, *Q;
	while(P->next != NULL) {
		Q = P;
		P = P->next;
		delete Q;
	}
}

bool LList::IsEmpty() const
{
	if (list == NULL) 
	{
		return true;
	}
	return false;
}

bool LList::Insert(InfoType * x_ptr)
{
	Node *P = list;
	while (P != NULL) {
		if (*P->infoPtr == *x_ptr) {
			return false;
		}
		P = P->next;
	}
	if (list != NULL) 
	{
		P = list;
		list = new Node(x_ptr);
		list->next = P;
	}
	else 
	{
		list = new Node(x_ptr);
	}
	return true;

}

bool LList::Delete(const InfoType &x)
{
	Node *Q, *P = list;

	while (P->next != NULL) {
		if (P->next->infoPtr == &x) {
			Q = P->next;
			P->next = Q->next;
			delete Q;
			return true;
		}
		P = P->next;
	}
	return false;
}

void LList::Display(ostream & out_stream) const
{
	Node *P = list;

	while (P != NULL) {
		out_stream << *P->infoPtr << '\n';
		P = P->next;
	}
}

LList & LList::operator=(const LList & assignFrom)
{
	LList returnlist;

	Node *P = list;
	while (P->next != NULL) {
		
		returnlist.Insert(P->infoPtr);
		P = P->next;
	}
	return returnlist;
}
