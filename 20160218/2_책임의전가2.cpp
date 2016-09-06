#include "ioacademy.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace ioacademy;

// http://d.pr/n/JAxG
// 책임의 전가(책임의 고리)
// : Chain of Responsibility
// 의도 : 이벤트 발생시 처리되지 않을 경우 다음 객체에게 전달한다.
//        처리될 때까지 고리에 따라 이벤트를 전달한다.
//       -> 이벤트와 이벤트 처리 객체 간의 결합도를 줄일 수 있다.

// 활용 : 1. MFC의 메뉴 메세지
//          View -> Document -> Frame -> App 순서로 전달된다.
//        2. Cocoa Touch Event(리스폰더 체인)
//          View -> ParentView -> ViewController -> ParentViewController -> AppDelegate

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
			// self->onLButtonDown();
			self->fireLButtonDown();
			break;
		case WM_KEYDOWN:
			self->onKeyDown();
			break;
		}
		return 0;
	}

	// 아래 코드가 책임의 전가 패턴의 핵심입니다.
	void fireLButtonDown()
	{
		// 1. 먼저 자신이 처리를 시도합니다.
		if (onLButtonDown())
			return;

		// 2. 자신이 처리하지 않은 경우(가상함수를 재정의하지 않은 경우)
		//    부모에게 전달
		if (parent != 0)
			parent->fireLButtonDown();
	}

	virtual bool onLButtonDown() { return false; }
	virtual void onKeyDown() {}
};

map<int, Window*> Window::this_map;

//--------------------------
// 라이브러리 사용자 코드 입니다.
class MyWindow : public Window
{
public:
	virtual bool onLButtonDown()
	{
		cout << "LBUTTON" << endl;
		return false;
	}
};

class ImageView : public Window
{
public:
	virtual bool onLButtonDown()
	{
		cout << "Image Click" << endl;
		return false;
	}
};

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