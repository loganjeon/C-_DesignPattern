// 1_참조계수
#include <iostream>
using namespace std;

// 객체의 수명을 참조 계수로 관리하는 경우가 많습니다.
// android, chromium, webkit, firefox
class Image
{
	int mCount;
public:
	Image() : mCount(0) {}
	~Image() { cout << "Image 파괴" << endl; }

	void addRef() { ++mCount; }
	void release() { if (--mCount == 0) delete this; }
};

// http://d.pr/n/1gECX
int main()
{
	Image* p1 = new Image;
	p1->addRef();			// 규칙 1. 객체를 만들면 참조 계수 증가

	Image* p2 = p1;
	p2->addRef();			// 규칙 2. 객체 포인터를 복사하면 참조 계수 증가

	p2->release();			// 규칙 3. 객체 포인터 사용후 참조 계수 감소
	p1->release();
}