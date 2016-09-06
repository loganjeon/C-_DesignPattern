// 4_State3
#include <iostream>
using namespace std;

// http://d.pr/n/1fHVn
// ��� 2. ���ϴ� ���� �����Լ��� �и� - Item�� ���� ������ ���Ѵ�.
// 4_State - ���¿� ���� ������ ��ȭ

class Hero
{
	int gold;
public:
	virtual void run() { cout << "run" << endl; }
	virtual void attack() { cout << "attack" << endl; }
};

// �������� ȹ�濡 ���� ������ �����ϱ� ���� ����� �̿��� ����
class FastHero : public Hero
{
public:
	virtual void run() { cout << "Fast run" << endl; }
};


int main()
{
	Hero h; FastHero f;

	Hero* p = &h;   // �ʱ����
	p->run();		// 100gold
		
	p = &f;
	p->run();       // 100gold????
}