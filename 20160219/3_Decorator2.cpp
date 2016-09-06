// 3_Decorator2
#include <iostream>
using namespace std;

// �������� ��ü�� ���������� ����� ��ü�� �ٽ� ������ �� �־�� �Ѵ�.
// => �������� ��ü�� ���� �θ� �ʿ��ϴ�.

// ����� �ռ� : �ڽ��� �ڽ��� �����ϴ� �ռ�
// - ����� �ռ��� ����ϴ� ������ ���� => ���� �θ� ����ϴ� Ʈ�� ������ Ŭ���� ����
// 1. ����� �ռ��� ���� ���� ��ü : Composite
// 2. ����� �ռ��� ���� ������ ����� �߰� : Decorator

// http://d.pr/n/18NRj

struct Item
{
	virtual void print() = 0;
	virtual ~Item() {}
};

class Ticket : public Item
{
public:
	void print() { cout << "���� ����ȸ - 2016.12.25" << endl; }
};

// ���� : ������ ��� �߰� �����ϴ�.
// ��� ����(������, Decorator)�� ������ Ư¡�� �θ�� �����ؾ� �Ѵ�.
class Decorator : public Item
{
	Item& item;
public:
	Decorator(Item& t) : item(t) {}
	void print() { item.print(); }
};

class Ad1 : public Decorator
{
public:
	Ad1(Item& t) : Decorator(t) {}

	void print()
	{
		Decorator::print();
		cout << "�ڵ��� ����" << endl;
	}
};

class Ad2 : public Decorator
{
public:
	Ad2(Item& t) : Decorator(t) {}

	void print()
	{
		cout << "TV ����" << endl;
		Decorator::print();
	}
};


int main()
{
	Ticket ticket;

	Ad1 ad1(ticket);
	

	// ����� �߰��� ��ü�� �ٽ� ��� �߰��� �ϰ� �ʹٸ�?
	Ad2 ad2(ad1);    // ?

	ad2.print();
}

// http://d.pr/n/FIAz
// Decorator�� ������ ��
// JAVA�� IO Ŭ����

// FileInputStream fis = new FileInputStream("a.tar");
// BufferedInputStream bis = new BufferedInputStream(fis);
// TarInputStream tis = new TarInputStream(bis);

// ZipInputStream zis = new ZipInputStream(bis);

// zis.read();