// 1_�޼�����
// http://d.pr/n/1bpCg
#include "ioacademy.h"
#include <iostream>
#include <map>
using namespace std;
using namespace ioacademy;

// http://d.pr/n/B569

class Window;
struct AFX_MSG
{
	int message;
	void(Window::*handler)();
};

class Window
{
	int handle;

	static map<int, Window*> this_map;
public:
	void create()
	{
		handle = IoMakeWindow(foo);
		this_map[handle] = this;
	}

	// �Ʒ� �����Լ����� �޼��� ��(�迭)�� �����ؾ� �մϴ�.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		if (self == 0) 
			return 0;

		// 1. �޼��� �� �迭�� ���´�.
		AFX_MSG* msgArray = self->GetMessageMap();
		if (msgArray == 0)   // ó���� �޼����� ���� ���
			return 0;

		for (; msgArray->message != 0; msgArray++)
		{
			if (msgArray->message == msg)
			{
				void(Window::*f)() = msgArray->handler;
				(self->*f)();
			}
		}

		return 0;
	}
};

map<int, Window*> Window::this_map;

class MyWindow : public Window
{
public:
	void onLButtonDown() { cout << "LBUTTON" << endl; }
	
	// WM_KEYDOWN�� �߻����� ��, foo()�� �����غ�����.
	void foo() { cout << "key" << endl; }

	// ����ڴ� �Ʒ� �����Լ��� �������ؼ� �迭�� �����ؾ� �մϴ�.
	virtual AFX_MSG* GetMessageMap()
	{
		typedef void(Window::*HANDLER)();

		static AFX_MSG msgMap[] = {
			{ WM_LBUTTONDOWN, static_cast<HANDLER>(&MyWindow::onLButtonDown) },
			{ WM_KEYDOWN, static_cast<HANDLER>(&MyWindow::foo) },
			{0, 0}
		};

		return msgMap;
	}

};

int main()
{
	MyWindow w;
	w.create();		
	IoProcessMessage();
}

















