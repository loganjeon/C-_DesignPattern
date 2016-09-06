// 1_�湮��(Visitor)
// http://d.pr/n/1f4iv
#include <iostream>
using namespace std;

// http://d.pr/n/1deVL
// �湮��(Visitor) ����
// �ǵ� : ���� ��ü�� ���� ������ ������� ��ҿ� Ư�� ������ �����ϴ� ��ü
//        �پ��� ���� ��ü�� ��� �Լ��� �߰����� �ʰ� ����� �߰��� �� �ִ�.

// ���� : �ϳ��� �湮�ڴ� �پ��� ���� ��ü(�����̳�)�� ���� �� �ִ�.
// ���� : �������̽� ����̹Ƿ� ���� ���ϰ� �ִ�.
template <typename T>
struct node
{
	T data;
	node* next;

	node(const T& a, node* n) : data(a), next(n) {}
};

// ��� �湮�� ��ü�� �������̽�
template <typename T>
struct IVisitor
{
	virtual void visit(T& a) = 0;
	virtual ~IVisitor() {}
};

// ��� �湮�� ���(�����̳�, ���� ��ü)�� �������̽�
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
	// �Ʒ� �Լ��� ��Ȯ�ϰ� �����ϸ� �˴ϴ�.
	virtual void accept(IVisitor<T>* visitor)
	{
		node<T>* current = head;

		while (current)
		{
			visitor->visit(current->data);  //	�湮�ڿ��� ��� ��� ����
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

	// s�ȿ� ��� ��Ҹ� 2��� �ϰ� �ʹ�.
	// 1. ������ �����ϸ鼭 ��� ��Ҹ� 2��� �� �� �ٽ� ������ �ȴ�.
	// 2. Ư�� �۾��� ���� �ϰ� �ȴٸ�, ��� �Լ��� �߰��ϴ� ���� ����.
	//   s.twiceAll();
	// 3. list �� �ƴ϶� ��� �����̳ʰ� �ش��ϴ� �۾��� ���� �ϰ� �ȴ�.
	//    ����ڰ� ��ҿ� � ������ �����ϰ��� ���� �� �� ����.
	//   => �湮�� ������ �������.

	TwiceVisitor<int> tw;
	s.accept(&tw);

	ShowVisitor<int> sw;
	s.accept(&sw);


	// cout << s.front() << endl;
}
