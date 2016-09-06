// 3_Decorator2
#include <iostream>
using namespace std;

// 포장지는 객체를 포장하지만 포장된 객체를 다시 포장할 수 있어야 한다.
// => 포장지와 객체는 동일 부모가 필요하다.

// 재귀적 합성 : 자신이 자신을 포함하는 합성
// - 재귀적 합성을 사용하는 디자인 패턴 => 동일 부모를 사용하는 트리 구조의 클래스 계층
// 1. 재귀적 합성을 통한 복합 객체 : Composite
// 2. 재귀적 합성을 통한 동적인 기능의 추가 : Decorator

// http://d.pr/n/18NRj

struct Item
{
	virtual void print() = 0;
	virtual ~Item() {}
};

class Ticket : public Item
{
public:
	void print() { cout << "작은 음악회 - 2016.12.25" << endl; }
};

// 포함 : 동적인 기능 추가 가능하다.
// 모든 광고(포장지, Decorator)의 공통의 특징을 부모로 제공해야 한다.
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
		cout << "자동차 광고" << endl;
	}
};

class Ad2 : public Decorator
{
public:
	Ad2(Item& t) : Decorator(t) {}

	void print()
	{
		cout << "TV 광고" << endl;
		Decorator::print();
	}
};


int main()
{
	Ticket ticket;

	Ad1 ad1(ticket);
	

	// 기능을 추가한 객체에 다시 기능 추가를 하고 싶다면?
	Ad2 ad2(ad1);    // ?

	ad2.print();
}

// http://d.pr/n/FIAz
// Decorator의 패턴의 예
// JAVA의 IO 클래스

// FileInputStream fis = new FileInputStream("a.tar");
// BufferedInputStream bis = new BufferedInputStream(fis);
// TarInputStream tis = new TarInputStream(bis);

// ZipInputStream zis = new ZipInputStream(bis);

// zis.read();