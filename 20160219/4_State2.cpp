// 4_State2 - ���¿� ���� ������ ��ȭ
// http://d.pr/n/1iaQM
#include <iostream>
using namespace std;

// ��� 1. �������� ������ ���� ���� �б�
// ������ : �ű� �������� �߰��Ǹ� ���� �б⹮�� �߰� �Ǿ�� �Ѵ�.
//          OCP�� ������ �� ����.
class Hero
{
	int state;
public:
	void run() { 
		if (state == 1) 
			cout << "run" << endl;
		else if (state == 2)
			cout << "fast run" << endl;
	}
	
	
	
	void attack() { cout << "attack" << endl; }
};

int main()
{
	Hero hero;
	hero.run();
	hero.attack();
}