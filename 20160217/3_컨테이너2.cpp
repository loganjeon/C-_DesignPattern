// 3_컨테이너2
#include <iostream>
using namespace std;

// 컨테이너를 설계하는 기술 
// 1. object * 기반 컨테이너

class object
{
public:
	virtual ~object() {}
};

// 라이브러리 내의 모든 클래스는 object의 자식 클래스이어야 한다.
// Java, C# - Object / ObjC - NSObject / MFC - CObject / Qt - QObject

class Dialog : public object {};
class Point : public object {};
class Rect : public object {};

class Integer : public object
{
	int value;
public:
	Integer(int v) : value(v) {}
	int getValue() { return value; }
};

//--------------------------------------------
struct node
{
	object* data;
	node* next;

	node(object* a, node* n) : data(a), next(n) {}
};

class slist
{
	node* head;
public:
	slist() : head(0) {}

	// node의 생성자를 잘 활용한 코드 입니다.
	void push_front(object* a)
	{
		head = new node(a, head);
	}

	object* front() { return head->data; }
};

// http://d.pr/n/yBp1
// 단점 1. 타입 안정성이 떨어진다. 실수로 다른 타입을 넣어도
//         컴파일 타임 에러가 발생하지 않는다.
//      2. 값을 꺼낼 때 해당 타입으로 캐스팅해야 한다.
//      3. 객체가 아닌 표준 타입(primitive type)은 저장이 불가능하다.
//         즉 모든 표준 타입에 대한 래퍼 클래스가 필요하다.

// 장점 : 템플릿이 아니므로 하나의 구현을 통해 사용할 수 있다.
//        코드 메모리를 절약 가능하다.

int main()
{
	slist s;
	s.push_front(new Point);
	s.push_front(new Point);
	s.push_front(new Point);
	s.push_front(new Dialog);
	s.push_front(new Integer(10));  // s.add(10); -> auto boxing

	Integer* p = dynamic_cast<Integer*>(s.front()); 
	// int p = s.get(0); - auto unboxing

	// Dialog* p = dynamic_cast<Dialog*>(s.front()); // object* -> Dialog*

}