#include "LList.h"
#include "Fruit.h"
typedef Fruit InfoType;
//#define TESTING_LLIST
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
	list = NULL;
	while(P != NULL) {
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
	bool status = false;
	bool firstrun = true;
	Node *Q = list, *P = list;
	if (IsEmpty()) {
		list = new Node(x_ptr);
		status = true;
	}
	else if (*list->infoPtr > *x_ptr) {
		list = new Node(x_ptr, list);
		status = true;
	}
	else {
		while (P != NULL) {
			if (*P->infoPtr == *x_ptr) {
				status = false;
				break;
			}
			else if (P->next == NULL)
			{
				P->next = new Node(x_ptr);
				status = true;
				break;
			}
			
			else if (*P->next->infoPtr > *x_ptr) {
				P->next = new Node(x_ptr, P->next);
				status = true;
				break;
			}
			
			P = P->next;
		}
	}
	return status;
}

bool LList::Delete(InfoType *x)
{
	Node *Q = list, *P = list;
	bool firstrun = true;
	while (P != NULL) {
		if (*P->infoPtr == *x) {
			if (firstrun) {
				list = list->next;
			}
			Q->next = P->next;
			delete P;
			return true;
		}
		else
		{
			if (!firstrun) {
				Q = Q->next;
			}
			firstrun = false;
			P = P->next;
		}
		
	}
	return false;
}

void LList::Display(ostream & out_stream) const
{
	Node *P = list;

	while (P != NULL) {
		out_stream << P->infoPtr << '\n';
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

#ifdef TESTING_LLIST

// ------------------------------
// Testbed main
// ------------------------------
void main()
{
#include <iostream>
	// .... etc, to test all the methods.
	const int MAX_INPUT_LEN = 34;
	//-------------------------------------------------------
	// Don't touch any of this!
	//-------------------------------------------------------

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	Fruit *test = new Fruit();
	cin >> *test;

	LList *LL = new LList();
	LL->Insert(test);
	LL->Display(cout);

	LL->Delete(test);
	LL->Display(cout);

	Fruit *test2 = new Fruit();
	cin >> *test2;
	Fruit *test3 = new Fruit();
	cin >> *test3;

	LL->Insert(test2);
	LL->Insert(test3);

	LL->Display(cout);

	Fruit *test4 = new Fruit();
	cin >> *test4;

	LL->Insert(test4);
	LL->Delete(test3);
	LL->Display(cout);

	delete LL;

	delete test;
	_CrtDumpMemoryLeaks();
	int pause;
	cin >> pause;
}

#endif
