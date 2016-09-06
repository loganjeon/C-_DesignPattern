// 2_thiscall5

// 타이머 개념을 클래스로 캡슐화 해봅시다.
// http://d.pr/n/bG7F
#if 0


void foo(int id)
{
	cout << "foo: " << id << endl;
}

int main()
{
	int n1 = IoSetTimer(1000, foo);
	int n2 = IoSetTimer(500, foo);

	IoProcessMessage();  // 종료 되지 말고 메세지를 처리해라.
}
#endif

#include "ioacademy.h"
using namespace ioacademy;

#include <string>
#include <iostream>


#include <map>
using namespace std;

// http://d.pr/n/1aa1d
class Clock;

class Clock
{
	static map<int, Clock*> this_map;
	string name;
public:
	Clock(string s) : name(s) {}

	void start(int ms)
	{
		int id = IoSetTimer(ms, timerHandler);
		this_map[id] = this;
	}

	static void timerHandler(int id)
	{
		Clock* self = this_map[id];
		cout << self->name << endl;
		//     this->name 이 되어야 하는데, this가 없다.
	}
};

// 정적 멤버 변수는 외부 정의가 필요하다.
map<int, Clock*> Clock::this_map;


int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.start(1000);   // 1초에 한번씩 이름을 출력해야 합니다.
	c2.start(500);

	IoProcessMessage();
}