// 2_thiscall6
// http://d.pr/n/16Rfj
// Window�� Ŭ������ ĸ��ȭ �غ��ô�.

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
// ���̺귯�� ����� �ڵ� �Դϴ�.
class MyWindow : public Window
{
public:
	virtual void onLButtonDown() 
	{ cout << "LBUTTON" << endl; }
};

int main()
{
	MyWindow w;
	w.create();		//  �̼��� �����찡 ��������ϴ�.
					//  ���� ��ư�� ������ "LBUTTON"�̶�� ȣ��Ǿ��
	                //  �մϴ�.

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
