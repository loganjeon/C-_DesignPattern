// 상호참조
// http://d.pr/n/12jYB

#include <iostream>
using namespace std;

#include <memory>

// 상호 참조의 가능성이 있을 때는 참조 계수가 증가하면 안된다.
// weak_ptr은 shared_ptr과 호환되지만, 참조 계수가 증가하지 않습니다.

// 강한 참조, 약한 참조
// 이 개념은 참조 계수 기반으로 객체의 수명을 관리하는 모든 프레임워크에 제공됩니다.
//  sp, wp
// shared_ptr, weak_ptr

// Java, C#
// Reference, / SoftReference, WeakReference

// Obj-C
// weak - auto niling

// Map<String, Image> imageMap = new HashMap<>();
// Map<String, WeakReference<Image>> imageMap = new HashMap<>();
// WeakHashMap<> : 캐시를 전용으로 설계된 컨테이너



struct node
{
	int data;
	~node() { cout << "node 파괴" << endl; }

	weak_ptr<node> next;
};

int main()
{
	shared_ptr<node> p1(new node);
	shared_ptr<node> p2(new node);

	p1->next = p2;
	p2->next = p1;
}