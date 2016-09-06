#include <iostream>
using namespace std;

// Inside C++ Object : ½ºÅÄ¸³ ¸³¸¸, 1998
// http://d.pr/n/12C2p
class Animal
{
	int age;
public:
	virtual void cry() {}
	virtual void foo() {}
	virtual void goo() {}
};

class Dog : public Animal
{
	int color;
public:
	virtual void cry() {}
};

int main()
{
	Animal a;   cout << sizeof(a) << endl;
	Dog d;	    cout << sizeof(d) << endl;

	Animal* p = &d;
	p->cry();   // (*p)[0](p);
}