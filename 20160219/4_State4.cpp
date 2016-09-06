// 4_State4
#include <iostream>
using namespace std;

// Replace type code with Polymorphism
// => Replace type code with Strategy or State

// ������ ���Ͽ��� ���ϴ� ���� Ŭ������ ���� �������̽� ������� �и��ؼ�
// ��ü�ϴ� ������ 3���� �Դϴ�.
// "Strategy" : �˰����� ĸ��ȭ�ؼ� ���� �ð��� ��ü �����ϰ� �ϴ� ��
// "State"    : ��ü�� ���¿� ���� ������ ������ Ŭ������ ���� ��ü
// "Builder"  : ������ ���� �������� ��ü�� ��������,
//              �� ������ ���� ǥ���� �޶����� ��ü�� ���� ��

// http://d.pr/n/1GFj


// ��ü �ڽ��� ���� ���¿� ���� ������ �����ϴ� ���� - State Pattern
// ��� 3. ���ϴ� ���� �������̽� ����� Ŭ������ �и�
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

// �پ��� �����ۿ� ���� ������ �����Ѵ�.
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