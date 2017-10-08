#ifndef FRUIT
#define FRUIT
#include<iostream>
using namespace std;
class Fruit {

public:
	Fruit(char * in, char * code);
	bool operator>(Fruit a);
	bool operator==(Fruit a);
	bool operator!=(Fruit a);
	friend ostream &operator<<(ostream &out, Fruit a);

private:
	enum { CODE_LEN = 4 }; 
	enum { MAX_NAME_LEN = 30 }; // another way to declare constants!
	char *name;              // allocate memory (use new) - cstring, zero-terminated
	char code[CODE_LEN];     // NOT zero-terminated (be careful!)
};


#endif