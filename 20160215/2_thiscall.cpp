// 2_thiscall
// http://d.pr/n/16kwS
#include <iostream>
using namespace std;
// 1. 멤버 함수는 this가 전달되어야 한다.
// 2. 정적 멤버 함수는 this가 없다.
class Point 
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;             // this->x = a;
		y = b;             // this->y = b;
	}

	static void foo(int a)  // void foo(int a)
	{
		x = a;				// this->x = a; 가 되어야 하는데
					        // this가 없다.
	}

};

int main()
{
	Point::foo(10);   // static 멤버 함수는 객체 없이 호출 가능하다.


	Point p1, p2;
	p1.set(10, 20);		   // set(&p1, 10, 20)
	                       // push 20
	                       // push 10
	                       // mov ecx, &p1
}
// http://d.pr/n/yD7C