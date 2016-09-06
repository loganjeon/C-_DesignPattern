#include "ioacademy.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace ioacademy;

class Window
{
	int handle;

	static map<int, Window*> this_map;

	//--------------------------------
	Window* parent;					// 부모 윈도우는 하나이다.
	vector<Window*> children;       // 자식 윈도우는 여러개이다.
public:
	Window() : parent(0) {}

	void addChild(Window* p)
	{
		p->parent = this;
		children.push_back(p);

		IoAddChild(handle, p->handle);
	}
	//----------------------------------

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
	{
		cout << "LBUTTON" << endl;
	}
};

class ImageView : public Window
{
public:
	virtual void onLButtonDown()
	{
		cout << "Image Click" << endl;
	}
};

// http://d.pr/n/X766

int main()
{
	MyWindow w;
	w.create();		//  이순간 윈도우가 만들어집니다.
					//  왼쪽 버튼을 누르면 "LBUTTON"이라고 호출되어야
					//  합니다.

	ImageView w2;
	w2.create();

	w.addChild(&w2);
	IoProcessMessage();
}