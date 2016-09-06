// 4_State - 상태에 따른 동작의 변화
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