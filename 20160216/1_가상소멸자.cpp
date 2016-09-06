// 1_가상소멸자
#include <iostream>
using namespace std;

// http://d.pr/n/a9mN
// 1. 소멸자도 함수이다. 정적 바인딩을 한다.
// 2. 모든 부모 클래스의 소멸자는 반드시 가상함수 이어야 한다.
// 3. protected 소멸자 기법 - 반드시 캐스팅이 필요하다.

class Base
{
protected:
	~Base() {}

public:
	// virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived()  { cout << "자원 할당" << endl; }
	~Derived() { cout << "자원 해지" << endl; }
};

int main()
{
	Base* p = new Derived;
	delete static_cast<Derived*>(p);
	// delete p;
}




