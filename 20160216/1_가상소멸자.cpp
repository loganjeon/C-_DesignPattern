// 1_����Ҹ���
#include <iostream>
using namespace std;

// http://d.pr/n/a9mN
// 1. �Ҹ��ڵ� �Լ��̴�. ���� ���ε��� �Ѵ�.
// 2. ��� �θ� Ŭ������ �Ҹ��ڴ� �ݵ�� �����Լ� �̾�� �Ѵ�.
// 3. protected �Ҹ��� ��� - �ݵ�� ĳ������ �ʿ��ϴ�.

class Base
{
protected:
	~Base() {}

public:
	// virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived()  { cout << "�ڿ� �Ҵ�" << endl; }
	~Derived() { cout << "�ڿ� ����" << endl; }
};

int main()
{
	Base* p = new Derived;
	delete static_cast<Derived*>(p);
	// delete p;
}




