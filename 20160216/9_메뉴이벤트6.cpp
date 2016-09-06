#include <iostream>
using namespace std;


class Dialog
{
public:
	void close() { cout << "Dialog close" << endl; }
};

// http://d.pr/n/19dUN
// �̹� ǥ�ؿ� ������ �Լ� �����Ͱ� �ֽ��ϴ�.
// boost ���̺귯������ ���� �Ұ��� �Ǿ����ϴ�. boost.org
// function<> : C++11/14, tr1(2008��) - Visual Studio 2008 sp1, gcc 4.4
#include <functional>

void foo() { cout << "foo" << endl; }
void goo(int n) { printf("goo : %d\n", n); }
void hoo(int a, int b) { printf("hoo : %d %d\n", a, b); }
void koo(int a, int b, int c, int d)
{
	printf("koo : %d %d %d %d\n", a, b, c, d);
}

using namespace std::placeholders;

int main()
{
	function<void(int, int)> f = &hoo;
	f(10, 20);

	f = bind(&koo, 10, 20, std::placeholders::_1, _2);
	f(30, 40);

	f = bind(&koo, _2, 0, 7, _1);
	f(2, 3);
}

#if 0
int main()
{
	function<void(int)> f = &goo;
	f(10);

	f = bind(&hoo, _1, _1);
	f(30);

	f = bind(&koo, _1, 10, _1, 40);
	f(100);
}
#endif



#if 0
int main()
{
	function<void()> f;
	f = bind(&goo, 10);
	f();

	f = bind(&hoo, 10, 20);
	f();

	f = bind(&koo, 10, 20, 30, 40);
	f();
}
#endif


#if 0
int main()
{
	function<void()> f = &foo;
	f();

	Dialog dialog;
	f = bind(&Dialog::close, &dialog);
	f();
}
#endif