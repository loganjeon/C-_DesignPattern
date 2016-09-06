// 2_thiscall5

// Ÿ�̸� ������ Ŭ������ ĸ��ȭ �غ��ô�.
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

	IoProcessMessage();  // ���� ���� ���� �޼����� ó���ض�.
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
		//     this->name �� �Ǿ�� �ϴµ�, this�� ����.
	}
};

// ���� ��� ������ �ܺ� ���ǰ� �ʿ��ϴ�.
map<int, Clock*> Clock::this_map;


int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.start(1000);   // 1�ʿ� �ѹ��� �̸��� ����ؾ� �մϴ�.
	c2.start(500);

	IoProcessMessage();
}