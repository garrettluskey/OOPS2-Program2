#include "Catalog.h"

Catalog::Catalog()
{
	list = new LList();
}

void Catalog::print()
{
	cout << "Below are the fruits currently in the list\n";
	list->Display(cout);
	
}

void Catalog::insert()
{
	Fruit *newFruit = make();
	if (!list->Insert(newFruit)) {
		cout << "Already in list:   " << newFruit << '\n';
		delete newFruit;
	}
	else {
		cout << "Added to list:     ";
		cout << newFruit << '\n';
	}
}

void Catalog::del()
{
	
	Fruit *newFruit = make();
	
	if (list->Delete(newFruit)) {
		cout << "Deleted from list: ";
		cout << newFruit << '\n';
	}
	else {
		cout << "Wasn't in list:    ";
		cout << newFruit << '\n';
	}
	delete newFruit;

}

void Catalog::close()
{
	delete list;
}



Fruit *Catalog::make()
{
	Fruit *newFruit = new Fruit();
	cin >> *newFruit;
	return newFruit;
}
