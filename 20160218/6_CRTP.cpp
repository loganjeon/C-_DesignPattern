// 6_CRTP
#include <iostream>
using namespace std;

// CRTP : 부모 클래스가 템플릿인데, 자식에서 템플릿 인자로 자신의 이름을
//        전달하는 기술
// Mix-in Template

// Curiosly Recurring Template Pattern  

// 1. WTL 라이브러리 - Windows Template Libary
// : 비가상함수를 가상함수처럼 동작하게 만드는 기법.
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