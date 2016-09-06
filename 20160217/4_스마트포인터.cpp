// 4_����Ʈ������
#include <iostream>
using namespace std;

class Car
{
public:
	Car()  { cout << "�ڿ� ����" << endl; }
	~Car() { cout << "�ڿ� ����" << endl; }

	void go() { cout << "Car go" << endl; }
};

// ����Ʈ ������
// ���� : ������ ��ü�� �ٸ� Ŭ������ ������ ��Ȱ�� �ϴ� ��
// ���� ���� : -> �� * �����ڸ� �������ؼ� ������ ó�� ���̰� �����.
// ���� : ��¥ �����Ͱ� �ƴ϶� ��ü�̴�. ����/����/����/�Ҹ��� ��� ������
//        ������ �� �ִ�.

// http://d.pr/n/13mqN
// C++ ǥ�ؿ��� �̹� ����Ʈ �����Ͱ� �ֽ��ϴ�.
// auto_ptr<>(deprecated)
// C++11   : shared_ptr, unique_ptr, weak_ptr
// android : sp, wp, unique_ptr

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; }

	Car* operator->() { return obj;  }
	Car& operator*()  { return *obj; }
};

int main()
{
	Ptr p = new Car;
	
	p->go();    //  p->go()
	            //  obj->go()
	(*p).go();
}








