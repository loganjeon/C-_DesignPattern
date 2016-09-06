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

// Image*�� �ٷ� ����ϸ� ���� ����� �Ź� ���� �����ؾ� �Ѵ�.
// �����ϹǷ� ���� ����� �ڵ����� �����ϴ� Ŭ������ ������.

// ������ -> ����Ʈ ������
// ���Ͻ� : ���� ��Ҹ� ����ϴ� Ŭ����
//  ����Ʈ ���Ͻ� : ���� ��Ҹ� ����ؼ� �߰����� ������ �����ϴ� �븮��
//  ���� ���Ͻ� : ������ ����ϴ� �븮��

// http://d.pr/n/1loro
class ImageProxy
{
	Image* obj;
public:
	explicit ImageProxy(Image* p) : obj(p) { obj->addRef(); }   // ��Ģ 1.
	ImageProxy(const ImageProxy& p) : obj(p.obj)	   // ��Ģ 2. 
	{  obj->addRef(); }

	~ImageProxy() { obj->release(); }
};

int main()
{
	ImageProxy p1(new Image);
	// ImageProxy p1 = new Image;   
	ImageProxy p2 = p1;
}
#if 0	
int main()
{
	Image* p1 = new Image;
	p1->addRef();			// ��Ģ 1. ��ü�� ����� ���� ��� ����

	Image* p2 = p1;
	p2->addRef();			// ��Ģ 2. ��ü �����͸� �����ϸ� ���� ��� ����

	p2->release();			// ��Ģ 3. ��ü ������ ����� ���� ��� ����
	p1->release();
}
#endif