// 4_State - ���¿� ���� ������ ��ȭ
// http://d.pr/n/F8U0

#include <iostream>
using namespace std;

class Hero
{
public:
	void run()    { cout << "run" << endl; }
	void attack() { cout << "attack" << endl; }
};

int main()
{
	Hero hero;
	hero.run();
	hero.attack();
}