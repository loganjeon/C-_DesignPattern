// 6_CRTP
#include <iostream>
using namespace std;

// CRTP : �θ� Ŭ������ ���ø��ε�, �ڽĿ��� ���ø� ���ڷ� �ڽ��� �̸���
//        �����ϴ� ���
// Mix-in Template

// Curiosly Recurring Template Pattern  

// 1. WTL ���̺귯�� - Windows Template Libary
// : �񰡻��Լ��� �����Լ�ó�� �����ϰ� ����� ���.
//   http://d.pr/n/1hdSv
template <typename T> class Window
{
public:
	void msgLoop()
	{
		//....
		static_cast<T*>(this)->onClick();  // this->onclick()
	}

	void onClick() {}
};

class MyWindow : public Window<MyWindow>
{
public:
	// void onClick() { cout << "My window on click" << endl; }
};

int main()
{
	MyWindow w;

	w.msgLoop();
}