// 2_thiscall6
// http://d.pr/n/16Rfj
// Window를 클래스로 캡슐화 해봅시다.

#include "ioacademy.h"
#include <iostream>
#include <map>
using namespace std;
using namespace ioacademy;

// http://d.pr/n/sY9R
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

	static int foo(int handle, int msg, int param1, int param2)
	{
		Window* self = this_map[handle];
		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->onLButtonDown();
			break;
		case WM_KEYDOWN:
			self->onKeyDown();
			break;
		}
		return 0;
	}

	virtual void onLButtonDown() {}
	virtual void onKeyDown() {}
};

map<int, Window*> Window::this_map;



//--------------------------
// 라이브러리 사용자 코드 입니다.
class MyWindow : public Window
{
public:
	virtual void onLButtonDown() 
	{ cout << "LBUTTON" << endl; }
};

int main()
{
	MyWindow w;
	w.create();		//  이순간 윈도우가 만들어집니다.
					//  왼쪽 버튼을 누르면 "LBUTTON"이라고 호출되어야
	                //  합니다.

	IoProcessMessage();
}


















#if 0
// http://d.pr/n/19U11
int foo(int handle, int msg, int param1, int param2)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		cout << "Left Button Down" << endl;
		break;
	case WM_KEYDOWN:
		cout << "Key Down" << endl;
		break;
	}
	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);
	// int h2 = IoMakeWindow(foo);

	IoProcessMessage();
}
#endif
