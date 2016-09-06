// 2_추상클래스
#include <iostream>
using namespace std;

// http://d.pr/n/15Fa6

// 정의 : 순수 가상함수가 1개 이상 있는 클래스
// 의도 : 구체 클래스에게 특정 함수를 반드시 만들라고 지시하는 것
class Shape
{
public:
	virtual void draw() = 0;   // 순수 가상 함수(pure virtual function)
};

// draw()의 구현부를 제공하지 않는다면, 역시 추상클래스가 된다.
class Rect : public Shape
{
};

int main()
{
	Shape s;  // 추상 클래스는 객체를 만들 수 없다.
	Rect r;
}