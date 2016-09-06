// 2_thiscall3
#include <iostream>
using namespace std;

// 멤버 함수와 함수 포인터의 이야기
// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
// 2. 일반 함수 포인터에 정적 멤버 함수의 주소를 담을 수 있다.
// 3. 멤버 함수 포인터를 만들고 사용하는 방법.
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

	// f();      // 될까요? error! this가 없다.
	Dialog dialog;
	(dialog.*f)();  // 될까요?
}


#if 0
int main()
{
	void(*f1)() = &foo;
	// void(*f2)() = &Dialog::close;
	void(*f2)() = &Dialog::goo;
}
#endif



