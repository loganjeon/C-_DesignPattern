// 2_thiscall
// http://d.pr/n/16kwS
#include <iostream>
using namespace std;
// 1. ��� �Լ��� this�� ���޵Ǿ�� �Ѵ�.
// 2. ���� ��� �Լ��� this�� ����.
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
		x = a;				// this->x = a; �� �Ǿ�� �ϴµ�
					        // this�� ����.
	}

};

int main()
{
	Point::foo(10);   // static ��� �Լ��� ��ü ���� ȣ�� �����ϴ�.


	Point p1, p2;
	p1.set(10, 20);		   // set(&p1, 10, 20)
	                       // push 20
	                       // push 10
	                       // mov ecx, &p1
}
// http://d.pr/n/yD7C