// 9_메뉴이벤트3
#include <iostream>
using namespace std;

// 
// 
// http://d.pr/f/124Ax

// 2. 함수 포인터 방식의 이벤트 처리
//   iPhone : Target-Action
//   C#     : delegate
//   MFC, wxWidget: Message Map
//   Qt     : Signal + SLOT

// C++의 표준 라이브러리에는 범용 함수 포인터라는 개념이 없습니다.
// http://d.pr/n/19UeI
class Dialog
{
public:
	void close() { cout << "Dialog close" << endl; }
	void open() { cout << "open" << endl; }
};

template <typename T>
class MenuItem
{
	void(T::*handler)();
	T* obj;
public:
	void setHandler(void(T::*h)(), T* o)
	{
		handler = h;
		obj = o;
	}

	void command()
	{
		(obj->*handler)();
	}
};

// http://d.pr/n/1bVm5
int main()
{
	MenuItem<Dialog> m, m2;
	Dialog dialog;
	m.setHandler(&Dialog::close, &dialog);
	m2.setHandler(&Dialog::open, &dialog);
	m.command();
	m2.command();
}