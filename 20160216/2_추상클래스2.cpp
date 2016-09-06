#include <iostream>
using namespace std;

// 2_추상클래스2
// 결합도 : '클래스 간의 서로 다른 책임들이 얽혀 있는 상호 의존도 정도'

// 1. 카메라 사용자와 카메라 제작자 사이의 규칙을 먼저 설계한다.
//   (인터페이스, 계약서, 프로토콜)

struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}
	// 인터페이스는 결국 부모이다. 가상 소멸자가 필요하다.
};

// 2. 진짜 카메라는 없지만, 규칙이 있다. 규칙대로만 사용하면 된다.
class Person
{
public:
	void takePicture(ICamera* p) { p->take(); }
};

// 3. "모든 카메라는 위의 클래스로 부터 상속받아야 한다." 라고 하지 말고
//    "모든 카메라는 위의 인터페이스를 구현해야 한다."
class Camera : public ICamera
{
public:
	virtual void take() {
		cout << "take picture with Camera" << endl;
	}
};

// 핵심 : 교체 가능하려면 인터페이스가 필요하다.
// DIP(Dependency Inversion Principle) : 의존관계 역전 원칙
// 클라이언트는 구체 클래스에 의존하는 것이 아니라 인터페이스나 추상 클래스에 의존해야
// 한다는 원칙.

// http://d.pr/n/1clhH
// 약한 결합(loosely coupling) : 하나의 클래스가 다른 클래스를 사용할 때
//                               부모인 추상 클래스를 사용해서 접근하는 것.
// "교체 가능한 유연한 디자인" => OCP 를 만족한다.

class SmartPhone : public ICamera
{
public:
	virtual void take() {

	}
};



int main()
{
	Person p;
	Camera c;
	SmartPhone sp;

	p.takePicture(&sp);
}






#if 0
class Camera
{
public:
	void take() { cout << "take picture with Camera" << endl; }
};

class SmartPhone
{
public:
	void take() { cout << "take picture with SmartPhone" << endl; }
};


class Person
{
public:
	void takePicture(Camera* p) { p->take(); }
};

int main()
{
	Person p;
	Camera c;

	p.takePicture(&c);
}
#endif