// 4_State4
#include <iostream>
using namespace std;

// Replace type code with Polymorphism
// => Replace type code with Strategy or State

// 디자인 패턴에서 변하는 것을 클래스로 만들어서 인터페이스 기반으로 분리해서
// 교체하는 패턴은 3가지 입니다.
// "Strategy" : 알고리즘을 캡슐화해서 실행 시간에 교체 가능하게 하는 것
// "State"    : 객체의 상태에 따라 동작을 정의한 클래스를 만들어서 교체
// "Builder"  : 동일한 구축 공정으로 객체를 만들지만,
//              각 공정에 따른 표현이 달라지는 객체를 만들 때

// http://d.pr/n/1GFj


// 객체 자신의 내부 상태에 따라 행위를 변경하는 패턴 - State Pattern
// 방법 3. 변하는 것을 인터페이스 기반의 클래스로 분리
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}
};

class Hero
{
	IState* state;
public:
	void setState(IState* p) { state = p; }

	void run() { state->run(); }
	void attack() { state->attack(); }
};

// 다양한 아이템에 따른 동작을 정의한다.
class NormalState : public IState
{
public:
	virtual void run() { cout << "run" << endl; }
	virtual void attack() { cout << "attack" << endl; }
};

class FastState : public IState 
{
public:
	virtual void run() { cout << "fast run" << endl; }
	virtual void attack() { cout << "fast attack" << endl; }
};

int main()
{
	NormalState ns; FastState fs;

	Hero hero;
	hero.setState(&ns);
	hero.run();
	
	
	hero.setState(&fs);
	hero.attack();
}