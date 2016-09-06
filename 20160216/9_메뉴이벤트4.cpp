// 9_메뉴이벤트4
#include <iostream>
using namespace std;

// http://d.pr/n/kNl7
// 일반 함수와 모든 클래스의 멤버 함수를 보관하는 범용적 함수 포인터
// 타입을 설계해보자.


// 3. 일반 함수 포인터와 멤버 함수 포인터를 하나의 개념으로 다루기 위해서는
//    공통의 부모, 즉 인터페이스가 필요하다.
struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};


// 1. 일반 함수 포인터의 역활을 수행하는 클래스를 설계하자.
class FunctionCommand : public ICommand
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionCommand(HANDLER h) : handler(h) {}

	void execute() { handler(); }
};

// 2. 멤버 함수 포인터의 역활을 수행하는 클래스를 설계해보자.
template<typename T>
class MemberCommand : public ICommand
{
	typedef void(T::*HANDLER)();
	HANDLER handler;
	T*      object;
public:
	MemberCommand(HANDLER h, T* o) : handler(h), object(o) {}
	void execute() { (object->*handler)(); }
};

void foo() { cout << "foo" << endl; }
class Dialog
{
public:
	void close() { cout << "Dialog close" << endl; }
};

// 4. 클래스 템플릿은 암시적 추론이 불가능하다.
//   함수 템플릿을 통한 객체 생성을 제공해주면, 암시적 추론이 가능합니다.
template <typename T>
MemberCommand<T>* cmd(void (T::*f)(), T* o)
{
	return new MemberCommand<T>(f, o);
}

// 5. 라이브러리 일관성을 위해 FunctionCommand를 만드는 cmd도 제공합니다.
FunctionCommand* cmd(void(*f)())
{
	return new FunctionCommand(f);
}

int main()
{
	Dialog dialog;
	ICommand* p = cmd(&Dialog::close, &dialog);
	p->execute();

	p = cmd(&foo);
	p->execute();
}


#if 0
int main()
{
	ICommand* p = new FunctionCommand(&foo);
	p->execute();

	Dialog dialog;
	p = new MemberCommand<Dialog>(&Dialog::close, &dialog);
	p->execute();
}
#endif




#if 0
int main()
{
	Dialog dialog;

	MemberCommand<Dialog> mc(&Dialog::close, &dialog);
	mc.execute();
}
#endif

// http://d.pr/n/RETn



#if 0

int main()
{
	FunctionCommand fc(&foo);
	fc.execute();
}
#endif














