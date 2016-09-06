// C++11 표준에는 이미 참조 계수 기반의 스마트 포인터가 있습니다.
// shared_ptr<>

// https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2011-Scott-Andrei-and-Herb-Ask-Us-Anything#time=04m34s

// http://d.pr/n/1i501
#include <iostream>
using namespace std;

#include <memory>
// shared_ptr 은 TR1에 포함되어 있습니다.
// 2008년도 이후 컴파일러는 대부분 포함하고 있습니다.
// boost 라이브러리에서 처음 소개되었습니다.

class Car
{
public:
	~Car() { cout << "객체 파괴" << endl; }
};

void foo(shared_ptr<Car> r) {
}

int main()
{
	shared_ptr<Car> p(new Car);


	shared_ptr<int> p1(new int);  // p1 = new int;

	*p1 = 10;

	shared_ptr<int> p2 = p1;	  // 이 순간 참조계수가 증가합니다.
	cout << *p2 << endl;

}

