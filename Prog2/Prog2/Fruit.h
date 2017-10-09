#ifndef FRUIT
#define FRUIT
#include<iostream>
using namespace std;
class Fruit {

public:
	Fruit();
	~Fruit();
	bool operator>(Fruit a);
	bool operator==(Fruit a) const;
	bool operator!=(Fruit a);
	void operator=(Fruit a);
	friend ostream &operator<<(ostream &out, const Fruit *a);
	friend istream &operator>>(istream &in, Fruit &a);
private:
	enum { CODE_LEN = 4 }; 
	enum { MAX_NAME_LEN = 30 }; // another way to declare constants!
	char *name;              // allocate memory (use new) - cstring, zero-terminated
	char *code;     // NOT zero-terminated (be careful!)
};


#endif