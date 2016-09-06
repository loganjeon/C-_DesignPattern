// C++11 ǥ�ؿ��� �̹� ���� ��� ����� ����Ʈ �����Ͱ� �ֽ��ϴ�.
// shared_ptr<>

// https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2011-Scott-Andrei-and-Herb-Ask-Us-Anything#time=04m34s

// http://d.pr/n/1i501
#include <iostream>
using namespace std;

#include <memory>
// shared_ptr �� TR1�� ���ԵǾ� �ֽ��ϴ�.
// 2008�⵵ ���� �����Ϸ��� ��κ� �����ϰ� �ֽ��ϴ�.
// boost ���̺귯������ ó�� �Ұ��Ǿ����ϴ�.

class Car
{
public:
	~Car() { cout << "��ü �ı�" << endl; }
};

void foo(shared_ptr<Car> r) {
}

int main()
{
	shared_ptr<Car> p(new Car);


	shared_ptr<int> p1(new int);  // p1 = new int;

	*p1 = 10;

	shared_ptr<int> p2 = p1;	  // �� ���� ��������� �����մϴ�.
	cout << *p2 << endl;

}

