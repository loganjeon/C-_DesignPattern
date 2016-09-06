// 1_참조계수
#include <iostream>
using namespace std;

// http://d.pr/n/ZJBN
class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	virtual ~RefCountedObject() { cout << "Object 파괴" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete this; }
};


template <typename T>
class Ptr
{
	T* obj;
public:
	explicit Ptr(T* p) : obj(p) { obj->addRef(); }   // 규칙 1.
	Ptr(const Ptr& p) : obj(p.obj)	   // 규칙 2. 
	{
		obj->addRef();
	}

	~Ptr() { obj->release(); }
};

class Image : public RefCountedObject {};
class Car : public RefCountedObject {};

int main()
{
	Ptr<Car> p1(new Car);
	Ptr<Car> p2 = p1;
}
