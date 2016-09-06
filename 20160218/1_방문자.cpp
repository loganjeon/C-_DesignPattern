// 1_방문자(Visitor)
// http://d.pr/n/1f4iv
#include <iostream>
using namespace std;

// http://d.pr/n/1deVL
// 방문자(Visitor) 패턴
// 의도 : 복합 객체의 내부 구조에 상관없이 요소에 특정 연산을 수행하는 객체
//        다양한 복합 객체에 멤버 함수를 추가하지 않고도 기능을 추가할 수 있다.

// 장점 : 하나의 방문자는 다양한 복합 객체(컨테이너)에 사용될 수 있다.
// 단점 : 인터페이스 기반이므로 성능 저하가 있다.
template <typename T>
struct node
{
	T data;
	node* next;

	node(const T& a, node* n) : data(a), next(n) {}
};

// 모든 방문자 객체의 인터페이스
template <typename T>
struct IVisitor
{
	virtual void visit(T& a) = 0;
	virtual ~IVisitor() {}
};

// 모든 방문의 대상(컨테이너, 복합 객체)의 인터페이스
template <typename T>
struct IAcceptor
{
	virtual void accept(IVisitor<T>* visitor) = 0;
	virtual ~IAcceptor() {}
};

template <typename T>
class slist : public IAcceptor<T>
{
	node<T>* head;
public:
	//--------------------
	// 아래 함수만 정확하게 이해하면 됩니다.
	virtual void accept(IVisitor<T>* visitor)
	{
		node<T>* current = head;

		while (current)
		{
			visitor->visit(current->data);  //	방문자에게 모든 요소 전달
			current = current->next;
		}

	}

	//--------------------
	slist() : head(0) {}

	void push_front(const T& a)
	{
		head = new node<T>(a, head);
	}

	T& front() { return head->data; }
};

template <typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { a *= 2; }
};

template <typename T> class ShowVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& a) { cout << a << endl; }
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// s안에 모든 요소를 2배로 하고 싶다.
	// 1. 루프를 수행하면서 모든 요소를 2배로 한 후 다시 넣으면 된다.
	// 2. 특정 작업을 자주 하게 된다면, 멤버 함수를 추가하는 것이 좋다.
	//   s.twiceAll();
	// 3. list 뿐 아니라 모든 컨테이너가 해당하는 작업을 자주 하게 된다.
	//    사용자가 요소에 어떤 연산을 수행하고자 할지 알 수 없다.
	//   => 방문자 패턴을 사용하자.

	TwiceVisitor<int> tw;
	s.accept(&tw);

	ShowVisitor<int> sw;
	s.accept(&sw);


	// cout << s.front() << endl;
}
