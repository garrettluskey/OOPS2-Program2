#ifndef FRUIT
#define FRUIT
#include<iostream>
using namespace std;
class Fruit {

public:
	Fruit(); // allocates code to have 4 numbers(as characters)
	~Fruit(); //deletes name pointer(cstring)
	
	bool operator>(Fruit a);	//returns true if the PLU is greater than the object on right otherwise returns false
	bool operator==(Fruit &a) const;	//if name and code match both fruit classes returns true otherwise false
	bool operator!=(Fruit const a);	//if code does not match both fruits returns true else false
	void operator=(Fruit const a);	//sets left hand sides name and code equal to right hand sides name and code

	friend ostream &operator<<(ostream &out, const Fruit *a);	//returns output stream formatted with name and code
	friend istream &operator>>(istream &in, Fruit &a);	//saves input in name and code sections
private:
	enum { CODE_LEN = 4 }; 
	enum { MAX_NAME_LEN = 30 }; // another way to declare constants!
	char *name;              // allocate memory (use new) - cstring, zero-terminated
	char code[CODE_LEN];     // NOT zero-terminated (be careful!)
};


#endif