// 5_싱글톤3
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

	// 참고 : 자바의 지연된 초기화를 사용하는 싱글톤
	//      : IODH idiom

	// 아래의 패턴은 C++에서는 절대 사용하지 않습니다.
	// 1. CPU의 비순차 명령 처리에 의해 멀티 코어 환경에서는 제대로 동작을
	//    보장하지 않습니다.

	// 2. 더 좋은 방법이 존재합니다. 
	//    C++11/14에서의 힙에 생성하는 싱글톤
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