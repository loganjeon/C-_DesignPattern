// 2_thiscall3
#include <iostream>
using namespace std;

// ��� �Լ��� �Լ� �������� �̾߱�
// 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ���� �� ����.
// 2. �Ϲ� �Լ� �����Ϳ� ���� ��� �Լ��� �ּҸ� ���� �� �ִ�.
// 3. ��� �Լ� �����͸� ����� ����ϴ� ���.
class Dialog
{
public:
	static void goo() { cout << "goo" << endl; }

	void close() // void close(Dialog* this)
	{ cout << "Dialog close" << endl; }
};

void foo() { cout << "foo" << endl; }

// http://d.pr/n/1kpGm
int main()
{
	void(Dialog::*f)() = &Dialog::close;

	// f();      // �ɱ��? error! this�� ����.
	Dialog dialog;
	(dialog.*f)();  // �ɱ��?
}


#if 0
int main()
{
	void(*f1)() = &foo;
	// void(*f2)() = &Dialog::close;
	void(*f2)() = &Dialog::goo;
}
#endif



