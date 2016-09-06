// ��ȣ����
// http://d.pr/n/12jYB

#include <iostream>
using namespace std;

#include <memory>

// ��ȣ ������ ���ɼ��� ���� ���� ���� ����� �����ϸ� �ȵȴ�.
// weak_ptr�� shared_ptr�� ȣȯ������, ���� ����� �������� �ʽ��ϴ�.

// ���� ����, ���� ����
// �� ������ ���� ��� ������� ��ü�� ������ �����ϴ� ��� �����ӿ�ũ�� �����˴ϴ�.
//  sp, wp
// shared_ptr, weak_ptr

// Java, C#
// Reference, / SoftReference, WeakReference

// Obj-C
// weak - auto niling

// Map<String, Image> imageMap = new HashMap<>();
// Map<String, WeakReference<Image>> imageMap = new HashMap<>();
// WeakHashMap<> : ĳ�ø� �������� ����� �����̳�



struct node
{
	int data;
	~node() { cout << "node �ı�" << endl; }

	weak_ptr<node> next;
};

int main()
{
	shared_ptr<node> p1(new node);
	shared_ptr<node> p2(new node);

	p1->next = p2;
	p2->next = p1;
}