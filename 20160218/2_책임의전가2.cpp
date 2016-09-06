#include "ioacademy.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using namespace ioacademy;

// http://d.pr/n/JAxG
// å���� ����(å���� ��)
// : Chain of Responsibility
// �ǵ� : �̺�Ʈ �߻��� ó������ ���� ��� ���� ��ü���� �����Ѵ�.
//        ó���� ������ ���� ���� �̺�Ʈ�� �����Ѵ�.
//       -> �̺�Ʈ�� �̺�Ʈ ó�� ��ü ���� ���յ��� ���� �� �ִ�.

// Ȱ�� : 1. MFC�� �޴� �޼���
//          View -> Document -> Frame -> App ������ ���޵ȴ�.
//        2. Cocoa Touch Event(�������� ü��)
//          View -> ParentView -> ViewController -> ParentViewController -> AppDelegate

class Window
{
	int handle;

	static map<int, Window*> this_map;

	//--------------------------------
	Window* parent;					// �θ� ������� �ϳ��̴�.
	vector<Window*> children;       // �ڽ� ������� �������̴�.
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

	// �Ʒ� �ڵ尡 å���� ���� ������ �ٽ��Դϴ�.
	void fireLButtonDown()
	{
		// 1. ���� �ڽ��� ó���� �õ��մϴ�.
		if (onLButtonDown())
			return;

		// 2. �ڽ��� ó������ ���� ���(�����Լ��� ���������� ���� ���)
		//    �θ𿡰� ����
		if (parent != 0)
			parent->fireLButtonDown();
	}

	virtual bool onLButtonDown() { return false; }
	virtual void onKeyDown() {}
};

map<int, Window*> Window::this_map;

//--------------------------
// ���̺귯�� ����� �ڵ� �Դϴ�.
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
	w.create();		//  �̼��� �����찡 ��������ϴ�.
					//  ���� ��ư�� ������ "LBUTTON"�̶�� ȣ��Ǿ��
					//  �մϴ�.

	ImageView w2;
	w2.create();

	w.addChild(&w2);
	IoProcessMessage();
}