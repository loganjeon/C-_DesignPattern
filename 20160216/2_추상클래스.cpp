// 2_�߻�Ŭ����
#include <iostream>
using namespace std;

// http://d.pr/n/15Fa6

// ���� : ���� �����Լ��� 1�� �̻� �ִ� Ŭ����
// �ǵ� : ��ü Ŭ�������� Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��
class Shape
{
public:
	virtual void draw() = 0;   // ���� ���� �Լ�(pure virtual function)
};

// draw()�� �����θ� �������� �ʴ´ٸ�, ���� �߻�Ŭ������ �ȴ�.
class Rect : public Shape
{
};

int main()
{
	Shape s;  // �߻� Ŭ������ ��ü�� ���� �� ����.
	Rect r;
}