// 4_State3
#include <iostream>
using namespace std;

// http://d.pr/n/1fHVn
// 방법 2. 변하는 것을 가상함수로 분리 - Item에 따라 동작은 변한다.
// 4_State - 상태에 따른 동작의 변화

class Hero
{
	int gold;
public:
	virtual void run() { cout << "run" << endl; }
	virtual void attack() { cout << "attack" << endl; }
};

// 아이템의 획득에 따른 동작을 변경하기 위해 상속을 이용한 버전
class FastHero : public Hero
{
public:
	virtual void run() { cout << "Fast run" << endl; }
};


int main()
{
	Hero h; FastHero f;

	Hero* p = &h;   // 초기상태
	p->run();		// 100gold
		
	p = &f;
	p->run();       // 100gold????
}