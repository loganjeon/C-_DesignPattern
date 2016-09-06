// 2_thiscall4
// 스레드 API를 클래스로 캡슐화 해봅시다.
#include <iostream>
using namespace std;

#include <Windows.h> // pthread.h
// http://d.pr/n/1gdaw

class Thread
{
public:
	void run() { CreateThread(0, 0, _threadLoop, this, 0, 0); }

	// 1. 아래 함수가 정적 멤버 함수일 수 밖에 없는 이유를 정확히
	//    알아야 합니다.
	// 2. this가 없으므로 스레드 함수 인자로 this를 전달하는 기술
	static DWORD __stdcall _threadLoop(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);

		self->threadLoop();    // threadLoop(self);
		return 0;
	}

	virtual bool threadLoop()
	{ return false; }
};



// 아래 클래스는 라이브러리의 사용자 입니다.
class MyThread : public Thread
{
public:
	virtual bool threadLoop()
	{
		cout << "MyThread threadLoop" << endl;
		return true;
	}
};

int main()
{
	MyThread t;
	t.run();   // 이 순간에 스레드가 생성되어서 가상 함수인 threadLoop를
	           // 수행해야 합니다.
	getchar();
}


#if 0
// http://d.pr/n/1fVTYs


DWORD __stdcall foo(void* p)
{
	cout << "Thread start" << endl;
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, 0, 0, 0);
	getchar();
}
#endif
// http://d.pr/n/11Jz8

// http://d.pr/f/7es9
// ioacademy.h 를 다운받으세요