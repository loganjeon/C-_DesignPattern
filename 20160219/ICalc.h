#ifndef CALC_H
#define CALC_H

class RefCountedObject
{
	int mCount;
public:
	RefCountedObject() : mCount(0) {}
	virtual ~RefCountedObject() {}

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

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};





// ICalc.h
struct ICalc : public RefCountedObject
{
	virtual int add(int, int) = 0;
	virtual int sub(int, int) = 0;
	virtual ~ICalc() {}
};

#endif
