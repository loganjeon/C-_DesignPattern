// 3_Decorator(포장지) 패턴 
#include <iostream>
using namespace std;

class Ticket
{
public:
	void print() { cout << "작은 음악회 - 2016.12.25" << endl; }
};

class Ad1 : public Ticket
{
public:
	void print()
	{
		Ticket::print();		// 원래 기능을 사용한다. - super.print();
		cout << "자동차 광고" << endl;
	}
};

class Ad2 : public Ad1
{
public:
	void print()
	{
		cout << "TV 광고" << endl;
		Ad1::print();
	}
};

// http://d.pr/n/1j6eI
// 상속을 통한 기능 추가는 부작용이 많습니다.
// 상속 : 정적인 기능 추가


int main()
{
	Ad2 ticket;
	ticket.print();
}