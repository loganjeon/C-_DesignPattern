// 1_�������
#include <iostream>
using namespace std;

// http://d.pr/n/ZJBN
class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	virtual ~RefCountedObject() { cout << "Object �ı�" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete this; }
};


template <typename T>
class Ptr
{
	T* obj;
public:
	explicit Ptr(T* p) : obj(p) { obj->addRef(); }   // ��Ģ 1.
	Ptr(const Ptr& p) : obj(p.obj)	   // ��Ģ 2. 
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
