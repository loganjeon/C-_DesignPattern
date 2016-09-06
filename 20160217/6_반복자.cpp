// 6_반복자
#include <iostream>
using namespace std;

// 반복자 패턴(Iterator Pattern)
// : 컨테이너 또는 복합 객체의 내부 구조에 상관없이
//   요소를 열거할 수 있는 객체

// http://d.pr/n/tdAV
template <typename T>
struct node
{
	T data;
	node* next;

	node(const T& a, node* n) : data(a), next(n) {}
};

template <typename T> class slist_iterator
{
	node<T>* current;
public:
	slist_iterator(node<T>* p = 0) : current(p) {}

	// 이동과 값을 얻는 연산자 오버로딩을 제공해야 한다.
	// 즉 배열에서의 포인터의 역활과 동일하게 만들어야 한다.
	T& operator*() { return current->data; }
	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	bool operator!=(const slist_iterator& t) { return current != t.current; }
	bool operator==(const slist_iterator& t) { return current == t.current; }
};

// 모든 컨테이너에서는 자신의 처음과 끝 다음을 가르키는 반복자를
// 꺼낼 수 있어야 한다. : begin(), end()
template <typename T>
class slist
{
	node<T>* head;
public:
	slist() : head(0) {}

	// 모든 컨테이너 설계자는 자신의 반복자 이름을
	// 미리 약속된 형태로 외부로 알려야 한다.
	typedef slist_iterator<T> iterator;

	// 반복자를 꺼내는 함수
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
	slist_iterator<T> end()   { return slist_iterator<T>(0); }

	void push_front(const T& a)
	{
		head = new node<T>(a, head);
	}

	T& front() { return head->data; }
};

template <typename T1, typename T2>
T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;

	return first;
}

// List<Integer> s = new LinkedList<>();
// s.add(10);
// ....



#include <list>
#include <vector>
int main()
{
	list<int> s;
	s.push_back(10);
	s.push_back(20);
	s.push_back(30);

	for (auto e : s)
		cout << e << endl;

#if 0
	auto p = s.begin();
	while (p != s.end()) {
		cout << *p << endl;
		++p;
	}
#endif

#if 0
	slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
	if (p != s.end())
		cout << *p << endl;
#endif
}