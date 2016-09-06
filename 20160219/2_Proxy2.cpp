// 2_Proxy2
#include <iostream>
#include "ioacademy.h"
using namespace std;
using namespace ioacademy;

// ������ �����ڴ� Ŭ���̾�Ʈ���� ���������� ���� ���񽺸� �̿��� �� �ֵ���
// ������ ��Ҹ� ����� �� �ִ� Ŭ������ �����ؾ� �մϴ�.
// Remote Proxy
// http://d.pr/n/17wYG

// Proxy�� �Ϻ��ϰ� ������ ����� �� �־�� �մϴ�.
// ������ ������ ������ �Լ��� �����ϱ�� ��ӵǾ�� �մϴ�.
// => �������̽�
struct ICalc
{
	virtual void add(int, int) = 0;
	virtual void sub(int, int) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int handle;
public:
	Calc() { handle = IoFindServer("CalcServer"); }

	int add(int a, int b) { return IoSendServer(handle, 1, a, b); }
	int sub(int a, int b) { return IoSendServer(handle, 2, a, b); }
};

int main()
{
	Calc* calc = new Calc;

	cout << calc->add(1, 2) << endl;
	cout << calc->sub(1, 2) << endl;
}



#if 0
int main()
{
	int handle = IoFindServer("CalcServer");
	cout << "���� ��ȣ: " << handle << endl;

	while (1)
	{
		cout << IoSendServer(handle, 1, 1, 2) << endl;
		getchar();

		cout << IoSendServer(handle, 2, 1, 2) << endl;
		getchar();
	}
}
#endif