// 5_싱글톤3
#include <iostream>
using namespace std;

// http://d.pr/n/1brET
class Mutex
{
public:
	void lock() { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }

	// 동기화 객체 사용시 예외가 발생하면 데드락의 확률이 있습니다.
	// 생성자/소멸자로 동기화 객체를 관리하면 편리합니다.
	
	// RAII(Resource Acqusion Is Intialize) 라는 기술
	//  : 자원을 자동으로 해지해줄 뿐 아니라 예외가 발생하여도 자원 누수가 발생하지
	//    않는다.
	// C++11/14 - mutex, lock_guard
	class AutoLock
	{
		Mutex& mLock;
	public:
		inline AutoLock(Mutex& m) : mLock(m) { mLock.lock(); }
		inline ~AutoLock() { mLock.unlock(); }
	};
};

#include <mutex>

class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&);
	void operator=(const Cursor&);

	static Cursor* sInstance;
	static Mutex   sLock;
public:
	static Cursor& getInstance()
	{
		// Mutex::AutoLock al(sLock);
		lock_guard<Mutex> al(sLock);
		// sLock.lock();
		if (sInstance == 0)
			sInstance = new Cursor;  // 예외가 발생할 위험이 있습니다. std::bad_alloc
		// sLock.unlock();
		return *sInstance;
	}
};

Cursor* Cursor::sInstance = 0;
Mutex   Cursor::sLock;


int main()
{
	Cursor& c1 = Cursor::getInstance();
}