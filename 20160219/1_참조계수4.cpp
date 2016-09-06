// 1_참조계수
http://d.pr/n/6a90
http://d.pr/n/1cny7

#include <iostream>
using namespace std;

// 가상 소멸자의 오버 헤드 없이 참조 계수 기반 클래스를 만드는 기술
// RefBase, LightRefBase 
template <typename T>
class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	~RefCountedObject() { cout << "Object 파괴" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete static_cast<T*>(this); }
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

class Image : public RefCountedObject<Image> {};
class Car : public RefCountedObject<Car> {};

int main()
{
	Ptr<Car> p1(new Car);
	Ptr<Car> p2 = p1;
}
