// 4_State2 - 상태에 따른 동작의 변화
// http://d.pr/n/1iaQM
#include <iostream>
using namespace std;

// 방법 1. 아이템의 종류에 따른 조건 분기
// 문제점 : 신규 아이템이 추가되면 조건 분기문이 추가 되어야 한다.
//          OCP를 만족할 수 없다.
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