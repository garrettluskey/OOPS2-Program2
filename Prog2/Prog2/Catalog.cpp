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
	}
	else {
		cout << "Added to list:     ";
		cout << newFruit << '\n';
	}
}

void Catalog::del()
{
	cout << "Deleted from list: ";
	Fruit *newFruit = make();
	cout << newFruit << '\n';
	list->Delete(newFruit);

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
