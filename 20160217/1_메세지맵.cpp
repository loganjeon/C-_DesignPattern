// 1_메세지맵
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

	// 아래 가상함수에서 메세지 맵(배열)을 리턴해야 합니다.
	virtual AFX_MSG* GetMessageMap() { return 0; }

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		if (self == 0) 
			return 0;

		// 1. 메세지 맵 배열을 얻어온다.
		AFX_MSG* msgArray = self->GetMessageMap();
		if (msgArray == 0)   // 처리할 메세지가 없는 경우
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
	
	// WM_KEYDOWN가 발생했을 때, foo()를 연결해보세요.
	void foo() { cout << "key" << endl; }

	// 사용자는 아래 가상함수를 재정의해서 배열을 리턴해야 합니다.
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

















