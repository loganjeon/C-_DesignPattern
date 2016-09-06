// 3_�����̳�2
#include <iostream>
using namespace std;

// �����̳ʸ� �����ϴ� ��� 
// 1. object * ��� �����̳�

class object
{
public:
	virtual ~object() {}
};

// ���̺귯�� ���� ��� Ŭ������ object�� �ڽ� Ŭ�����̾�� �Ѵ�.
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

	// node�� �����ڸ� �� Ȱ���� �ڵ� �Դϴ�.
	void push_front(object* a)
	{
		head = new node(a, head);
	}

	object* front() { return head->data; }
};

// http://d.pr/n/yBp1
// ���� 1. Ÿ�� �������� ��������. �Ǽ��� �ٸ� Ÿ���� �־
//         ������ Ÿ�� ������ �߻����� �ʴ´�.
//      2. ���� ���� �� �ش� Ÿ������ ĳ�����ؾ� �Ѵ�.
//      3. ��ü�� �ƴ� ǥ�� Ÿ��(primitive type)�� ������ �Ұ����ϴ�.
//         �� ��� ǥ�� Ÿ�Կ� ���� ���� Ŭ������ �ʿ��ϴ�.

// ���� : ���ø��� �ƴϹǷ� �ϳ��� ������ ���� ����� �� �ִ�.
//        �ڵ� �޸𸮸� ���� �����ϴ�.

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