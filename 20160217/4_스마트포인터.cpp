// 4_스마트포인터
#include <iostream>
using namespace std;

class Car
{
public:
	Car()  { cout << "자원 생성" << endl; }
	~Car() { cout << "자원 해지" << endl; }

	void go() { cout << "Car go" << endl; }
};

// 스마트 포인터
// 개념 : 임의의 객체가 다른 클래스의 포인터 역활을 하는 것
// 구현 원리 : -> 와 * 연산자를 재정의해서 포인터 처럼 보이게 만든다.
// 장점 : 진짜 포인터가 아니라 객체이다. 생성/복사/대입/소멸의 모든 과정을
//        제어할 수 있다.

// http://d.pr/n/13mqN
// C++ 표준에는 이미 스마트 포인터가 있습니다.
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








