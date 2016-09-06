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

// Image*를 바로 사용하면 참조 계수를 매번 직접 관리해야 한다.
// 불편하므로 참조 계수를 자동으로 관리하는 클래스를 만들자.

// 포인터 -> 스마트 포인터
// 프록시 : 기존 요소를 대신하는 클래스
//  스마트 프록시 : 기존 요소를 대신해서 추가적인 연산을 수행하는 대리자
//  원격 프록시 : 서버를 대신하는 대리자

// http://d.pr/n/1loro
class ImageProxy
{
	Image* obj;
public:
	explicit ImageProxy(Image* p) : obj(p) { obj->addRef(); }   // 규칙 1.
	ImageProxy(const ImageProxy& p) : obj(p.obj)	   // 규칙 2. 
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
	p1->addRef();			// 규칙 1. 객체를 만들면 참조 계수 증가

	Image* p2 = p1;
	p2->addRef();			// 규칙 2. 객체 포인터를 복사하면 참조 계수 증가

	p2->release();			// 규칙 3. 객체 포인터 사용후 참조 계수 감소
	p1->release();
}
#endif