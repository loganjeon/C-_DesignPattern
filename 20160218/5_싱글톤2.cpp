#include <iostream>
using namespace std;

// 5_½Ì±ÛÅæ2
// Èü¿¡ ¸¸µå´Â ½Ì±ÛÅæ
// http://d.pr/n/1aQaG
class Mutex
{
public:
	void lock()   { cout << "mutex lock" << endl; }
	void unlock() { cout << "mutex unlock" << endl; }
};

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
		sLock.lock();
		if (sInstance == 0)
			sInstance = new Cursor;
		sLock.unlock();
		return *sInstance;
	}
};

Cursor* Cursor::sInstance = 0;
Mutex   Cursor::sLock;


int main()
{
	Cursor& c1 = Cursor::getInstance();
}