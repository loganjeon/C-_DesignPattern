// 6_�ݺ���2
// http://d.pr/n/1jiLX
#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	node* next;

	node(const T& a, node* n) : data(a), next(n) {}
};

// 1. ��� �ݺ����� �������̽��� �����Ѵ�.
// Java : Iterator, Iterable
// C#   : IEnumerator, IEnumerable
template <typename T>
struct IEnumerator
{
	virtual bool moveNext() = 0;		// ++
	virtual T& getObject() = 0;			// *
	
	virtual ~IEnumerator() {}
};

// slist�� �ݺ���
template <typename T> class slist_enumerator : public IEnumerator<T>
{
	node<T>* current;
public:
	slist_enumerator(node<T>* p = 0) : current(p) {}

	virtual bool moveNext()
	{
		current = current->next;
		return current;
	}

	virtual T& getObject() { return current->data; }
};

//------------------------------
// �����̳ʿ��� �ݺ��ڸ� ������
// 1. STL  : begin()/end() => �Ͻ��� ���(Generic ��� �������� Ư¡)
// 2. Java : �������̽� ����� �Լ��� ����Ѵ�. 

// ��� �����̳ʴ� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
template <typename T> struct IEnumerable
{
	virtual IEnumerator<T>* getEnumeratorN() = 0;
	virtual ~IEnumerable() {}
};

// http://d.pr/n/ahwq
template <typename T>
class slist : public IEnumerable<T>
{
	node<T>* head;
public:
	virtual IEnumerator<T>* getEnumeratorN()
	{ return new slist_enumerator<T>(head); }

	slist() : head(0) {}

	void push_front(const T& a)
	{
		head = new node<T>(a, head);
	}

	T& front() { return head->data; }
};

// �˰���
// STL : find(T)
// Java : find(Inteface*)
template <typename T>
void show(IEnumerator<T>* p)
{
	do {
		cout << p->getObject() << endl;
	} while (p->moveNext());
}

// http://d.pr/n/1ke8t
int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	cout << s.front() << endl;

	show(s.getEnumeratorN());
}
