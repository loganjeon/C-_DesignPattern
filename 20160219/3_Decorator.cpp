// 3_Decorator(������) ���� 
#include <iostream>
using namespace std;

class Ticket
{
public:
	void print() { cout << "���� ����ȸ - 2016.12.25" << endl; }
};

class Ad1 : public Ticket
{
public:
	void print()
	{
		Ticket::print();		// ���� ����� ����Ѵ�. - super.print();
		cout << "�ڵ��� ����" << endl;
	}
};

class Ad2 : public Ad1
{
public:
	void print()
	{
		cout << "TV ����" << endl;
		Ad1::print();
	}
};

// http://d.pr/n/1j6eI
// ����� ���� ��� �߰��� ���ۿ��� �����ϴ�.
// ��� : ������ ��� �߰�


int main()
{
	Ad2 ticket;
	ticket.print();
}