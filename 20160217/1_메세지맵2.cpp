// 1_�޼�����2
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


//-----------------------------------------
// GetMessageMap()�� �����ϴ� ��ũ�θ� ��������.

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
// 1. MFC�� wxWidget�̶�� GUI ���̺귯���� �� ������� ����Ǿ� �ֽ��ϴ�.
// �����Լ� ���̺��� ������带 ���̱� ���� ����ڰ� ���� ���̺��� �����
// �ϴ� ����Դϴ�.
// 2. ������ �ڵ带 ��ũ�η� �ܼ�ȭ �Ͽ����ϴ�.
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

















