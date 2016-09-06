// 7_가상함수의원리3
#include <iostream>
using namespace std;

// http://d.pr/n/1aD3F
class A
{
	int a;
public:
	virtual void foo() { cout << "A foo" << endl; }
};

class B
{
	int b;
public:
	virtual void goo() { cout << "B goo" << endl; }
};

int main()
{
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);

	p->goo();
}







