// 5_�̱���3
#include <iostream>
using namespace std;

// http://d.pr/n/1brET
class Mutex
{
public:
	void lock() { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }

	// ����ȭ ��ü ���� ���ܰ� �߻��ϸ� ������� Ȯ���� �ֽ��ϴ�.
	// ������/�Ҹ��ڷ� ����ȭ ��ü�� �����ϸ� ���մϴ�.
	
	// RAII(Resource Acqusion Is Intialize) ��� ���
	//  : �ڿ��� �ڵ����� �������� �� �ƴ϶� ���ܰ� �߻��Ͽ��� �ڿ� ������ �߻�����
	//    �ʴ´�.
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
			sInstance = new Cursor;  // ���ܰ� �߻��� ������ �ֽ��ϴ�. std::bad_alloc
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