// 1_�������
#include <iostream>
using namespace std;

// ��ü�� ������ ���� ����� �����ϴ� ��찡 �����ϴ�.
// android, chromium, webkit, firefox
class Image
{
	int mCount;
public:
	Image() : mCount(0) {}
	~Image() { cout << "Image �ı�" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete this; }
};

// http://d.pr/n/1gECX
int main()
{
	Image* p1 = new Image;
	p1->addRef();			// ��Ģ 1. ��ü�� ����� ���� ��� ����

	Image* p2 = p1;
	p2->addRef();			// ��Ģ 2. ��ü �����͸� �����ϸ� ���� ��� ����

	p2->release();			// ��Ģ 3. ��ü ������ ����� ���� ��� ����
	p1->release();
}