// 3_컨테이너3
// http://d.pr/n/1avtQ
#include <iostream>
using namespace std;
// 컨테이너를 설계하는 기술 
// 2. Template 기반 컨테이너
// 장점: 타입 안정성이 뛰어나고, 객체 뿐 아니라 표준 타입도 저장 가능하다.
//       값을 꺼낼 때 캐스팅도 필요 없다.

// 단점: template 이므로 여러 가지 타입에 대해 사용하면 slist의 기계어 코드가
//       많아 진다. 코드 메모리 오버 헤드가 있다.
// node, node<int>
template <typename T>
struct node
{
	T data;
	node* next;

	node(const T& a, node* n) : data(a), next(n) {}
};

template <typename T>
class slist
{
	node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& a)
	{
		head = new node<T>(a, head);
	}

	T& front() { return head->data; }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;
}



















