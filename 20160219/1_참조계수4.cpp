// 1_�������
http://d.pr/n/6a90
http://d.pr/n/1cny7

#include <iostream>
using namespace std;

// ���� �Ҹ����� ���� ��� ���� ���� ��� ��� Ŭ������ ����� ���
// RefBase, LightRefBase 
template <typename T>
class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	~RefCountedObject() { cout << "Object �ı�" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete static_cast<T*>(this); }
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

class Image : public RefCountedObject<Image> {};
class Car : public RefCountedObject<Car> {};

int main()
{
	Ptr<Car> p1(new Car);
	Ptr<Car> p2 = p1;
}
