// 3_�����̳�3
// http://d.pr/n/1avtQ
#include <iostream>
using namespace std;
// �����̳ʸ� �����ϴ� ��� 
// 2. Template ��� �����̳�
// ����: Ÿ�� �������� �پ��, ��ü �� �ƴ϶� ǥ�� Ÿ�Ե� ���� �����ϴ�.
//       ���� ���� �� ĳ���õ� �ʿ� ����.

// ����: template �̹Ƿ� ���� ���� Ÿ�Կ� ���� ����ϸ� slist�� ���� �ڵ尡
//       ���� ����. �ڵ� �޸� ���� ��尡 �ִ�.
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



















