// 2_thiscall4
// ������ API�� Ŭ������ ĸ��ȭ �غ��ô�.
#include <iostream>
using namespace std;

#include <Windows.h> // pthread.h
// http://d.pr/n/1gdaw

class Thread
{
public:
	void run() { CreateThread(0, 0, _threadLoop, this, 0, 0); }

	// 1. �Ʒ� �Լ��� ���� ��� �Լ��� �� �ۿ� ���� ������ ��Ȯ��
	//    �˾ƾ� �մϴ�.
	// 2. this�� �����Ƿ� ������ �Լ� ���ڷ� this�� �����ϴ� ���
	static DWORD __stdcall _threadLoop(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);

		self->threadLoop();    // threadLoop(self);
		return 0;
	}

	virtual bool threadLoop()
	{ return false; }
};



// �Ʒ� Ŭ������ ���̺귯���� ����� �Դϴ�.
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
	t.run();   // �� ������ �����尡 �����Ǿ ���� �Լ��� threadLoop��
	           // �����ؾ� �մϴ�.
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
// ioacademy.h �� �ٿ��������