// 6_�ݺ���
#include <iostream>
using namespace std;

// �ݺ��� ����(Iterator Pattern)
// : �����̳� �Ǵ� ���� ��ü�� ���� ������ �������
//   ��Ҹ� ������ �� �ִ� ��ü

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

	// �̵��� ���� ��� ������ �����ε��� �����ؾ� �Ѵ�.
	// �� �迭������ �������� ��Ȱ�� �����ϰ� ������ �Ѵ�.
	T& operator*() { return current->data; }
	slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	bool operator!=(const slist_iterator& t) { return current != t.current; }
	bool operator==(const slist_iterator& t) { return current == t.current; }
};

// ��� �����̳ʿ����� �ڽ��� ó���� �� ������ ����Ű�� �ݺ��ڸ�
// ���� �� �־�� �Ѵ�. : begin(), end()
template <typename T>
class slist
{
	node<T>* head;
public:
	slist() : head(0) {}

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸���
	// �̸� ��ӵ� ���·� �ܺη� �˷��� �Ѵ�.
	typedef slist_iterator<T> iterator;

	// �ݺ��ڸ� ������ �Լ�
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