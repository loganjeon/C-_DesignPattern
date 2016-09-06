#include <iostream>
using namespace std;

// http://d.pr/n/jk7a

struct ICommand
{
	virtual void execute() = 0;
	virtual ~ICommand() {}
};

class FunctionCommand : public ICommand
{
	typedef void(*HANDLER)();
	HANDLER handler;
public:
	FunctionCommand(HANDLER h) : handler(h) {}

	void execute() { handler(); }
};

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

template <typename T>
MemberCommand<T>* cmd(void (T::*f)(), T* o)
{
	return new MemberCommand<T>(f, o);
}

FunctionCommand* cmd(void(*f)())
{
	return new FunctionCommand(f);
}

void foo() { cout << "foo" << endl; }
class Dialog
{
public:
	void close() { cout << "Dialog close" << endl; }
};

class MenuItem
{
	ICommand* pCommand;
public:
	MenuItem() : pCommand(0) {}
	void setCommand(ICommand* p) { pCommand = p; }

	void command()
	{
		if (pCommand != 0)
			pCommand->execute();
	}
};

int main()
{
	MenuItem m;
	m.setCommand(cmd(&foo));
	m.command();

	Dialog dialog;
	m.setCommand(cmd(&Dialog::close, &dialog));
	m.command();
}