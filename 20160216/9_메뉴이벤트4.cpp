// 9_�޴��̺�Ʈ4
#include <iostream>
using namespace std;

// http://d.pr/n/kNl7
// �Ϲ� �Լ��� ��� Ŭ������ ��� �Լ��� �����ϴ� ������ �Լ� ������
// Ÿ���� �����غ���.


// 3. �Ϲ� �Լ� �����Ϳ� ��� �Լ� �����͸� �ϳ��� �������� �ٷ�� ���ؼ���
//    ������ �θ�, �� �������̽��� �ʿ��ϴ�.
struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};


// 1. �Ϲ� �Լ� �������� ��Ȱ�� �����ϴ� Ŭ������ ��������.
class FunctionCommand : public ICommand
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionCommand(HANDLER h) : handler(h) {}

	void execute() { handler(); }
};

// 2. ��� �Լ� �������� ��Ȱ�� �����ϴ� Ŭ������ �����غ���.
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

// 4. Ŭ���� ���ø��� �Ͻ��� �߷��� �Ұ����ϴ�.
//   �Լ� ���ø��� ���� ��ü ������ �������ָ�, �Ͻ��� �߷��� �����մϴ�.
template <typename T>
MemberCommand<T>* cmd(void (T::*f)(), T* o)
{
	return new MemberCommand<T>(f, o);
}

// 5. ���̺귯�� �ϰ����� ���� FunctionCommand�� ����� cmd�� �����մϴ�.
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














