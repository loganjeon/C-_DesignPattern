// 5_ΩÃ±€≈Ê5
#include <iostream>
using namespace std;

// http://d.pr/n/1gIS2
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

template <typename TYPE>
class Singleton
{
protected:
	Singleton() {}

private:
	Singleton(const Singleton&);
	void operator=(const Singleton&);

	static TYPE* sInstance;
	static Mutex   sLock;
public:

	static TYPE& getInstance()
	{
		Mutex::AutoLock al(sLock);
		if (sInstance == 0)
			sInstance = new TYPE;
		return *sInstance;
	}
};

template<typename TYPE>
TYPE* Singleton<TYPE>::sInstance = 0;

template<typename TYPE>
Mutex   Singleton<TYPE>::sLock;

class Cursor : public Singleton<Cursor>
{
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
}