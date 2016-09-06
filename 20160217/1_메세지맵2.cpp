// 1_메세지맵2
#include "ioacademy.h"
#include <iostream>
#include <map>
using namespace std;
using namespace ioacademy;

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


//-----------------------------------------
// GetMessageMap()을 생성하는 매크로를 제공하자.

#define DECLARE_MESSAGE_MAP()						\
	virtual AFX_MSG* GetMessageMap();

#define BEGIN_MESSAGE_MAP(classname)					\
	AFX_MSG* classname::GetMessageMap()					\
	{													\
		typedef void(Window::*HANDLER)();				\
		static AFX_MSG msgMap[] = {

#define ADD_MAP(message, handler)						\
			{ message, static_cast<HANDLER>(handler) },

#define END_MESSAGE_MAP()								\
			{ 0, 0 }									\
		};												\
		return msgMap;									\
	}

// http://d.pr/n/1jmwv
// 1. MFC와 wxWidget이라는 GUI 라이브러리가 이 방식으로 설계되어 있습니다.
// 가상함수 테이블의 오버헤드를 줄이기 위해 사용자가 직접 테이블을 만들게
// 하는 기술입니다.
// 2. 복잡한 코드를 매크로로 단순화 하였습니다.
class MyWindow : public Window
{
public:
	void onLButtonDown() { cout << "LBUTTON" << endl; }
	void foo() { cout << "key" << endl; }

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(MyWindow)
	ADD_MAP(WM_LBUTTONDOWN, &MyWindow::onLButtonDown)
	ADD_MAP(WM_KEYDOWN, &MyWindow::foo)
END_MESSAGE_MAP()




int main()
{
	MyWindow w;
	w.create();
	IoProcessMessage();
}

















