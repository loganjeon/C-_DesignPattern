// 5_�̱���3
#include <iostream>
using namespace std;

class Mutex
{
public:
	void lock() { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }

	class AutoLock
	{
		Mutex& mLock;
	public:
		inline AutoLock(Mutex& m) : mLock(m) { mLock.lock(); }
		inline ~AutoLock() { mLock.unlock(); }
	};
};

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&);
	void operator=(const Cursor&);

	// static Cursor* sInstance;
	static Mutex   sLock;
public:

	// ���� : �ڹ��� ������ �ʱ�ȭ�� ����ϴ� �̱���
	//      : IODH idiom

	// �Ʒ��� ������ C++������ ���� ������� �ʽ��ϴ�.
	// 1. CPU�� ����� ��� ó���� ���� ��Ƽ �ھ� ȯ�濡���� ����� ������
	//    �������� �ʽ��ϴ�.

	// 2. �� ���� ����� �����մϴ�. 
	//    C++11/14������ ���� �����ϴ� �̱���
	static Cursor& getInstance()
	{
		static Cursor* sInstance = new Cursor();
		return *sInstance;
	}


#if 0
	// DCLP(Double Checked Locking Pattern)
	static Cursor& getInstance()
	{
		if (sInstance == 0) {
			Mutex::AutoLock al(sLock);
			if (sInstance == 0)
				sInstance = new Cursor;
		}
		return *sInstance;
	}
#endif
};

Cursor* Cursor::sInstance = 0;
Mutex   Cursor::sLock;

int main()
{
	Cursor& c1 = Cursor::getInstance();
}